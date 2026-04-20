#ifndef FCTR_H
#define FCTR_H

#include <stddef.h>

typedef struct Order Order;

typedef struct {
    Item* item;
    size_t quantity;
} Requirement;

typedef struct {
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

typedef struct Order {
    char* item_name;
    float machine_qty;
    Order** components;
} Order;


Item* find_item(Database db, const char* item_name);
void get_string_input(char** string_storage);
void print_order_tree(Order** tree);
void calculate_tree(Database db, Order* tree, char* item_name, float qty);

#endif