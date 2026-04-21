#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

// void print_order_tree(Order** tree) {
//     // TODO

//     return;
// }

Order* get_order(Database db, char* item_name, float item_qty) {
    Item* item = find_item(db, item_name);
    if (item == NULL) {
        printf("Item (%s) not found.", item_name);
        return NULL;
    }

    const float ITEM_PER_MACHINE = item->batch_size / item->process_time_seconds;
    const float MACHINE_QTY = item_qty / ITEM_PER_MACHINE;

    const size_t REQUIREMENT_COUNT = item->requirement_count;
    Order** components = malloc(REQUIREMENT_COUNT * sizeof(Order));

    for (size_t i = 0; i < REQUIREMENT_COUNT; i++) {
        float component_qty = MACHINE_QTY * item->requirements[i].quantity;
        components[i] = get_order(db, item->requirements[i].item->name, component_qty);
    }

    Order* output = &(Order) {
        .item_name = item_name,
        .machine_qty = MACHINE_QTY,
        .components = components
    };

    return output;
}
