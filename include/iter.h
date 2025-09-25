#ifndef ITER_H 
#define ITER_H

#include "list.h"

typedef struct
{
    Node* iter;
}iter;


Node* begin(Mylist* l);


#endif