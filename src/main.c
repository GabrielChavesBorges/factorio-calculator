#include <stdio.h>
#include <stdlib.h>

#include "fctr.h"

extern Database db;

int main() {
    char* target_item_name = NULL;
    printf("Item: ");
    get_string_input(&target_item_name);
    fflush(stdout);

    int items_per_second;
    printf("Quantity per second: ");
    scanf("%d", &items_per_second);
    fflush(stdout);

    // find 

    Order* tree = NULL;
    calculate_tree(db, tree, target_item_name, items_per_second);
    
    return 0;
}
