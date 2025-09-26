#ifndef ITER_H 
#define ITER_H

#include "list.h"

typedef struct
{
    Node* iter;
}iter;


iter begin(Mylist* l);

char* next(iter* it);


#endif