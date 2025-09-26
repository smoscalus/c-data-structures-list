#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

typedef struct Node{
    char* data;
    struct Node* next; 
}Node;

typedef struct
{
    Node*  head;
    unsigned int size;
}Mylist;

Mylist createList()
{
    Mylist l;
    l.size = 0;
    l.head = NULL;
    return l;
}

void headpush(Mylist* l,char* obj)
{
    Node* newNode = malloc(sizeof(newNode));
    newNode->data = obj;
    newNode->next = l->head;
    l->head = newNode;
    l->size += 1;
}

void headpop(Mylist* l)
{
    if (l->head->next == NULL){
        printf("[ERROR]headPointerIsNULL");
        return;
    }

    Node* temp = l->head;
    l->head = l->head->next; 
    free(temp);
    
    if (l->size > 0)
        l->size--;
}

bool isEmpty(Mylist* l)
{
    return l->head == NULL;
}
