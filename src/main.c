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

    Order* tree = get_order(db, target_item_name, items_per_second);
    printf("\n\n");
    print_order_tree(tree);
    
    return 0;
}
