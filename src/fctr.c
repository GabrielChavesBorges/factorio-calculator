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

void print_calculation(Item* target_item, size_t items_per_second) {
    // final item calculation: items_per_second / batch_size;
    // total_required_qty_per_second = final_item_factories * requirement_qty
    // total_produced_per_second_per_machine = batch_size / process_time
    // requirement_machine_qty: total_required_qty_per_second / total_produced_per_second_per_machine

    return;
}

void calculation(Item* current_item, float required_qty, Order* order_tree) {
    if (parent_item == NULL) {
        return;
    }

    // calculate machine qty based on parent item
    float qty_per_machine = current_item->batch_size * current_item->process_time_seconds;
    float machine_qty = required_qty / qty_per_machine;
    
    // Tree tip condition
    if (current_item->requirement_count = 0) {
        return;
    }

    // call calculation on each requirement
    for (size_t i = 0; i < current_item->requirement_count; i++) {
        calculation(current_item->requirements[i]->item, machine_qty * current_item->requirements[i]->quantity);
    }
    
    return;

    // TODO: Figure how to store information in order tree so that it can be printed later
}
