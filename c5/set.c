#include <stdio.h>
#include "set.h"

IntSet set_new() {
    IntSet s;
    s.size = 0;
    return s;
}

void set_add(IntSet* s, int value) {
    for (int i = 0; i < s->size; i++) {
        if (s->data[i] == value) return;
    }
    s->data[s->size++] = value;
}

IntSet set_union(IntSet a, IntSet b) {
    IntSet result = set_new();
    for (int i = 0; i < a.size; i++) set_add(&result, a.data[i]);
    for (int i = 0; i < b.size; i++) set_add(&result, b.data[i]);
    return result;
}

IntSet set_intersection(IntSet a, IntSet b) {
    IntSet result = set_new();
    for (int i = 0; i < a.size; i++) {
        for (int j = 0; j < b.size; j++) {
            if (a.data[i] == b.data[j]) {
                set_add(&result, a.data[i]);
                break;
            }
        }
    }
    return result;
}

void set_print(IntSet s) {
    printf("{ ");
    for (int i = 0; i < s.size; i++) printf("%d ", s.data[i]);
    printf("}\n");
}

