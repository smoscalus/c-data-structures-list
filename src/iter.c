#include "stdio.h"
#include "../include/list.h"



typedef struct
{
    Node* iter;
}iter;


iter begin(Mylist* l)
{
    iter it; 
    if(l->head == NULL){
        printf("[ERROR]headPointerIsNULL");
        return it;
    }
    it.iter = l->head;

    return it;
}

char* next(iter* it)
{
    if (it == NULL || it->iter == NULL) 
        return NULL;
    char* data = it->iter->data;
    it->iter = it->iter->next;
    return data;
}