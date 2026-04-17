#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "fctr.h"

Item* find_item(Database* db, const char* item_name) {
    for (size_t i = 0; i < db->item_count; i++) {
        if (strcmp(db->items[i]->name, item_name) == 0) {
            return db->items[i];
        }
    }
    return NULL;
}

void get_string_input(char** string_storage, size_t* string_length) {
    int buffer;
    *string_storage = NULL;
    *string_length = 0;

    while (1) {
        buffer = getchar();
        if (buffer == '\n' || buffer == -1) {
            (*string_length)++;
            *string_storage = realloc(*string_storage, *string_length * sizeof(char));
            (*string_storage)[*string_length - 1] = '\0';
            break;
        }

        (*string_length)++;
        *string_storage = realloc(*string_storage, *string_length * sizeof(char));
        (*string_storage)[*string_length - 1] = buffer;
    }

    return;
}
