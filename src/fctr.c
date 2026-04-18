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

void get_string_input(char** string_storage) {
    int buffer = ' ';
    *string_storage = NULL;
    size_t string_length = 0;

    while (buffer != '\0') {
        buffer = getchar();
        if (buffer == '\n' || buffer == -1) {
            buffer = '\0';
        }

        string_length++;
        *string_storage = realloc(*string_storage, string_length * sizeof(char));
        (*string_storage)[string_length - 1] = buffer;
    }

    return;
}
