#include <stdio.h>
#include <stdlib.h>

#include "fctr.h"

extern Database db;

int main() {
    char* target_item = NULL;
    int items_per_second;

    printf("Item: ");
    get_string_input(&target_item);
    fflush(stdout);

    printf("Quantity per second: ");
    scanf("%d", &items_per_second);
    fflush(stdout);

    // find Item

    return 0;
}
