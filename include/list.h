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
    Node*  tail;
    unsigned int size;
}Mylist;

Mylist createList();
// _______________________________________________________________

void headpush(Mylist* l,char* obj);
void headpop(Mylist* l);
void tailpush(Mylist* l,char* obj);

// _______________________________________________________________

Node* find(Mylist* l, const char* val);
char* findValue(Mylist* l, const char* val);


Node* getByIndex(Mylist* l, unsigned int index);
char* getValueByIndex(Mylist* l, unsigned int index);

// _______________________________________________________________

bool isEmpty(Mylist* l);

#endif