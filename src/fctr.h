#ifndef FCTR_H
#define FCTR_H

#include <stddef.h>

typedef struct Order Order;
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
    Requirement* requirements;
} Item;

typedef struct {
    Item** items;
    size_t item_count;
} Database;

typedef struct Order {
    char* item_name;
    float machine_qty;
    Order** components;
} Order;


Item* find_item(Database db, const char* item_name);
void get_string_input(char** string_storage);
void print_order_tree(Order** tree);
Order* get_order(Database db, char* item_name, float item_qty);

#endif