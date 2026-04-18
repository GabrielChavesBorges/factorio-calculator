#include <stdio.h>
#include <stdlib.h>

#include "fctr.h"

extern Database db;

int main() {
    char* target_item_string = NULL;
    printf("Item: ");
    get_string_input(&target_item_string);
    fflush(stdout);

    int items_per_second;
    printf("Quantity per second: ");
    scanf("%d", &items_per_second);
    fflush(stdout);

    // find 
    Item* target_item;
    target_item = find_item(db, target_item_string);
    if (target_item == NULL) {
        printf("Item not found.");
        return 0;
    }

    printf("Target item: %s", target_item->name);
    
    return 0;
}
