#include "stdio.h"
#include "stdlib.h"
#include "string.h"

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


int main()
{
    Mylist l = createList();
    headpush(&l,"hi");
    headpush(&l,"priv");
    headpush(&l,"wirld");
    headpush(&l,"world");

    return 1;
}