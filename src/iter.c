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

// _______________________________________________________________

iter* next(iter* it)
{
    if (it && it->node)
        it->node = it->node->next;
}
char* nextvalue(iter* it)
{
    if (!it || !it->node || !it->node->next) return NULL;

    iter temp = *it;
    next(&temp);
    return temp.node ? temp.node->data : NULL;
}


char* get(iter* it)
{
    return it->node->data;
}

// _______________________________________________________________

bool equals(iter* it1, iter* it2)
{
    return it1->node->data == it2->node->data ? true : false;
}


void reset(iter* it, Mylist* l)
{
    if (l->head == NULL)
        printf("[ERORR]headPointerIsNULL");
    it->node = l->head;
}

// _______________________________________________________________

bool hasNext(iter* it)
{
    return it->node->next != NULL;
}


