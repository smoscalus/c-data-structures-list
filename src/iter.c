#include "stdio.h"
#include "../include/list.h"
#include <stdbool.h>


typedef struct
{
    Node* node;
}iter;


iter begin(Mylist* l)
{
    iter it; 
    if(l->head == NULL){
        printf("[ERROR]headPointerIsNULL");
        return it;
    }
    it.node = l->head;

    return it;
}

char* next(iter* it)
{
    if (it == NULL || it->node == NULL) 
        return NULL;
    char* data = it->node->data;
    it->node = it->node->next;
    return data;
}

bool hasNext(iter* it)
{
    return it->node->next != NULL;
}

void reset(iter* it, Mylist* l)
{
    if (l->head == NULL)
        printf("[ERORR]headPointerIsNULL");
    it->node->next = l->head;
}

char* get(iter* it)
{
    return it->node->data;
}

bool equals(iter* it1, iter* it2)
{
    return it1->node->data == it2->node->data ? true : false;
}

