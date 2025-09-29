#ifndef LIST_H
#define LIST_H

#include <stdbool.h>

typedef struct Node{
    char* data;
    struct Node* next; 
}Node;

typedef struct
{
    Node* head;
    unsigned int size;
}Mylist;

Mylist createList();

void headpush(Mylist* l,char* obj);
void headpop(Mylist* l);

char* find(Mylist* l, char* val);
char* getAt(Mylist* l, int index);

bool isEmpty(Mylist* l);

#endif