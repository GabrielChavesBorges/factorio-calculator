#include "fctr.h"

// Primary Items          | Name             | Batch | Time                      | Requirements
Item coal               = {"coal"            ,      1,  1.0 / DRILL_SPEED        , 0, NULL};
Item copper_ore         = {"copper ore"      ,      1,  1.0 / DRILL_SPEED        , 0, NULL};
Item iron_ore           = {"iron ore"        ,      1,  1.0 / DRILL_SPEED        , 0, NULL};
Item stone              = {"stone"           ,      1,  1.0 / DRILL_SPEED        , 0, NULL};
Item water              = {"water"           ,      1,  1.0 / OFFSHORE_PUMP_SPEED, 0, NULL};
// Derived Items
Item stone_brick        = {"stone brick"     ,      1,  3.2 / FURNACE_SPEED      , 1, (Requirement[]) {{ &stone, 2 }}};
Item iron_plate         = {"iron plate"      ,      1,  3.2 / FURNACE_SPEED      , 1, (Requirement[]) {{ &iron_ore, 1 }}};
Item steel_plate        = {"steel plate"     ,      1, 16.0 / FURNACE_SPEED      , 1, (Requirement[]) {{ &iron_plate, 5 }}};
Item iron_stick         = {"iron stick"      ,      2,  0.5 / ASSEMBLY_SPEED     , 1, (Requirement[]) {{ &iron_plate, 1 }}};
Item concrete           = {"concrete"        ,     10, 10.0 / ASSEMBLY_SPEED     , 3, (Requirement[]) {{ &iron_ore, 1 }, { &stone_brick, 5}, { &water, 100 }}};
Item refined_concrete   = {"refined concrete",     10, 15.0 / ASSEMBLY_SPEED     , 4, (Requirement[]) {{ &concrete, 20 }, { &iron_stick, 8 }, { &steel_plate, 1 }, { &water, 100 }}};

Item* all_items[] = {
    &coal,
    &copper_ore,
    &iron_ore,
    &stone,
    &water,
    &stone_brick,
    &iron_plate,
    &iron_stick,
    &steel_plate,
    &concrete,
    &refined_concrete,
};

Database db = {
    all_items,
    11
};
