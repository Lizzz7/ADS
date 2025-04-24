#include <stdio.h>
#include "set.h"

int main() {
    IntSet a = set_new();
    IntSet b = set_new();

    set_add(&a, 1);
    set_add(&a, 2);
    set_add(&a, 3);

    set_add(&b, 2);
    set_add(&b, 3);
    set_add(&b, 4);

    IntSet u = set_union(a, b);
    IntSet i = set_intersection(a, b);

    printf("Set A: "); set_print(a);
    printf("Set B: "); set_print(b);
    printf("Union: "); set_print(u);
    printf("Intersection: "); set_print(i);

    return 0;
}

