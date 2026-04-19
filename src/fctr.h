#ifndef FCTR_H
#define FCTR_H

#include <stddef.h>

typedef struct Item Item;

typedef struct {
    Item* item;
    size_t quantity;
} Requirement;

typedef struct Item {
    char* name;
    int batch_size;
    float process_time_seconds;
    size_t requirement_count;
    Requirement *requirements;
} Item;

typedef struct {
    Item **items;
    size_t item_count;
} Database;

typedef struct {
    char* item_name;
    float machine_qty;
} Order;


Item* find_item(Database db, const char* item_name);
void get_string_input(char** string_storage);
void print_calculation(Item* target_item, size_t items_per_second);

#endif