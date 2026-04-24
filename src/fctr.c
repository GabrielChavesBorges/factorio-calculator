#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#include "fctr.h"

Item* find_item(Database db, const char* item_name) {
    for (size_t i = 0; i < db.item_count; i++) {
        if (strcmp(db.items[i]->name, item_name) == 0) {
            return db.items[i];
        }
    }
    return NULL;
}

void get_string_input(char** string_storage) {
    int buffer = ' ';
    *string_storage = NULL;
    size_t string_length = 0;

    while (buffer != '\0') {
        buffer = getchar();
        if (buffer == '\n' || buffer == -1) {
            buffer = '\0';
        }

        string_length++;
        *string_storage = realloc(*string_storage, string_length * sizeof(char));
        (*string_storage)[string_length - 1] = buffer;
    }

    return;
}

static void print_order_tree_inner(Order* tree, bool* is_depth_cleared, size_t depth) {
    
    printf("%s: %.2f\n", tree->item_name, tree->machine_qty);

    for (size_t i = 0; i < tree->component_count; i++) {
        for (size_t j = 0; j < depth; j++) {
            printf(is_depth_cleared[j] ? "     " : " |   ");
        }

        bool is_last_sibling = (i == tree->component_count - 1);
        printf(is_last_sibling ? " `-- " : " +-- ");

        size_t next_depth = depth + 1;
        bool* is_depth_cleared_copy = malloc(next_depth * sizeof(bool));
        if (is_depth_cleared_copy == NULL) {
            fprintf(stderr, "\n\nMalloc failed!!! Some items will be missing.\n\n");
            return;
        }

        memcpy(is_depth_cleared_copy, is_depth_cleared, depth * sizeof(bool));
        is_depth_cleared_copy[depth] = is_last_sibling;
        print_order_tree_inner(tree->components[i], is_depth_cleared_copy, next_depth);
        free(is_depth_cleared_copy);
    }
}

void print_order_tree(Order* tree) {
    bool* is_depth_cleared = NULL;
    print_order_tree_inner(tree, is_depth_cleared, 0);
    free(is_depth_cleared);
}

Order* get_order(Database db, char* item_name, float item_qty) {
    Item* item = find_item(db, item_name);
    if (item == NULL) {
        printf("Item \"%s\" not found.", item_name);
        return NULL;
    }

    const float ITEM_PER_MACHINE = item->batch_size / item->process_time_seconds;
    const float MACHINE_QTY = item_qty / ITEM_PER_MACHINE;

    const size_t REQUIREMENT_COUNT = item->requirement_count;
    Order** components = malloc(REQUIREMENT_COUNT * sizeof(Order));

    for (size_t i = 0; i < REQUIREMENT_COUNT; i++) {
        const float COMPONENT_QTY = MACHINE_QTY * item->requirements[i].quantity / item->process_time_seconds; 
        components[i] = get_order(db, item->requirements[i].item->name, COMPONENT_QTY);
    }

    Order* output = malloc(sizeof(Order));
    if (output == NULL) {
        return NULL;
    }
    output->item_name = item_name;
    output->machine_qty = MACHINE_QTY;
    output->component_count = REQUIREMENT_COUNT;
    output->components = components;

    return output;
}
