#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Node{
    char* data;
    struct Node* next; 
}Node;

typedef struct
{
    char* head;
    char* tail;
    unsigned int size;
}Mylist;

Mylist createList()
{
    Mylist l;
    l.size = 0;
    l.head = NULL;
    l.tail = NULL;
    return l;
}

void headpush(Mylist* l,char* obj)
{
    Node* newNode = malloc(sizeof(newNode));
    newNode->data = obj;
    newNode->next = l->head;
    l->head = newNode;
}


int main()
{
    return 1;
}