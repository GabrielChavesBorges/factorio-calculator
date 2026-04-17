#include "fctr.h"

// Primary Items
Item iron_ore   = {"iron ore",      1,  1.0, 0, NULL};

// Derived Items
Item iron_plate = {"iron plate",    1,  3.2, 1, (Requirement[]) {{ &iron_ore, 1 }}};

Item* all_items[] = {
    &iron_ore,
    &iron_plate,
};

Database db = {
    all_items,
    2
};
