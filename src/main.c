#include <stdio.h>
#include <stdlib.h>

#include "fctr.h"

extern Database db;

int main() {
    char* target_item = NULL;
    size_t target_item_length = 0;
    int quantity;

    printf("Item: ");
    get_string_input(&target_item, &target_item_length);
    fflush(stdout);

    printf("Quantity per second: ");
    scanf("%d", &quantity);
    fflush(stdout);

    printf("Item: %s, quantity: %d", target_item, quantity);

    return 0;
}
