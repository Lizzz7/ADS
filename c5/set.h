#ifndef SET_H
#define SET_H

typedef struct {
    int data[100];
    int size;
} IntSet;

IntSet set_new();
void set_add(IntSet* s, int value);
IntSet set_union(IntSet a, IntSet b);
IntSet set_intersection(IntSet a, IntSet b);
void set_print(IntSet s);

#endif

