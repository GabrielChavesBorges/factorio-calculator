#ifndef FCTR_H
#define FCTR_H

#include <stddef.h>

#define BURNER_MINING_DRILL_SPEED 0.25
#define ELECTRIC_MINING_DRILL_SPEED 0.5
#define STONE_FURNACE_SPEED 1.0
#define STEEL_FURNACE_SPEED 2.0
#define ASSEMBLING_MACHINE_1_SPEED 0.5
#define ASSEMBLING_MACHINE_2_SPEED 0.75
#define ASSEMBLING_MACHINE_3_SPEED 1.25

#define OFFSHORE_PUMP_SPEED 1200.0
#define PUMPJACK_SPEED 1.0

#define DRILL_SPEED ELECTRIC_MINING_DRILL_SPEED
#define FURNACE_SPEED STEEL_FURNACE_SPEED
#define ASSEMBLY_SPEED ASSEMBLING_MACHINE_2_SPEED

// 0.5
// units/sec = mining_speed / mining_time
// seconds for 1 unit = mining_time / mining_speed

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
    size_t component_count;
    Order** components;
} Order;


Item* find_item(Database db, const char* item_name);
void get_string_input(char** string_storage);
void print_order_tree(Order* tree);
Order* get_order(Database db, char* item_name, float item_qty);

#endif