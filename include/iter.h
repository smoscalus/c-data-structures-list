#ifndef ITER_H 
#define ITER_H

#include "list.h"
#include <stdbool.h>

typedef struct
{
    Node* node;
}iter;


iter begin(Mylist* l);

iter* next(iter* it);
bool hasNext(iter* it);

void reset(iter* it, Mylist* l);

char* get(iter* it);

bool equals(iter* it1, iter* it2);

#endif