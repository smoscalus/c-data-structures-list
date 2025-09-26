#include "stdio.h"
#include "../include/list.h"



typedef struct
{
    Node* iter;
}iter;


iter begin(Mylist* l)
{
    iter it; 
    it.iter = l->head;
    return it;
}

char* next(iter* it)
{
    if (it == NULL || it->iter == NULL) 
        return NULL;
    it->iter = it->iter->next;
    return it->iter ? it->iter->data : NULL;
}