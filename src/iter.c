#include "../include/list.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    Node* node;
}iter;

// _______________________________________________________________

iter begin(Mylist* l)
{
    iter it = { .node = NULL}; 
    if(l) it.node = l->head;
    return it;
}
iter end(Mylist* l)
{
    iter it = { .node = NULL}; 
    if(l) it.node = l->tail;
    return it;
}

// _______________________________________________________________

void next(iter* it)
{
    if (it && it->node)
        it->node = it->node->next;
}
char* nextvalue(iter* it)
{
    if (!it || !it->node || !it->node->next) return NULL;

    return it->node->next->data;
}

char* get(iter* it)
{
    if (!it || !it->node) return NULL;
    

    return it->node->data;
}

// _______________________________________________________________

bool equals(iter* it1, iter* it2)
{
    if (!it1 || !it2 || !it1->node || !it2->node) return false;


    return strcmp(it1->node->data,it2->node->data) == 0;
}


void reset(iter* it, Mylist* l)
{
    if (!it) return;
    
    if (l->head == NULL){
        printf("[ERORR]headPointerIsNULL\n");
        return;
    }
    it->node = l->head;
}

// _______________________________________________________________

bool hasNext(iter* it)
{
    return it && it->node && it->node->next != NULL;
}


