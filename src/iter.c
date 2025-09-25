#include "stdio.h"
#include "../include/list.h"



typedef struct
{
    Node* iter;
}iter;


Node* begin(Mylist* l)
{
    iter it; 
    it.iter = l->head;
    return it.iter;
}
