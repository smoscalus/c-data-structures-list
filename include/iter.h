#ifndef ITER_H 
#define ITER_H

#include "list.h"
#include <stdbool.h>

typedef struct
{
    Node* node;
}iter;


iter begin(Mylist* l);

// _______________________________________________________________

iter* next(iter* it);
char* nextvalue(iter* it);

char* get(iter* it);

// _______________________________________________________________

void reset(iter* it, Mylist* l);
bool equals(iter* it1, iter* it2);

// _______________________________________________________________

bool hasNext(iter* it);

#endif