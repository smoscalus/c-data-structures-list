#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdio.h>

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

void headpush(Mylist* l,char* out);
void headpop(Mylist* l,char* out);


void tailpush(Mylist* l,char* out);
void tailpop(Mylist* l,char* out);

// _______________________________________________________________

Node* find(Mylist* l, const char* val);
char* findValue(Mylist* l, const char* val);


Node* getByIndex(Mylist* l, unsigned int index);
char* getValueByIndex(Mylist* l, unsigned int index);

// _______________________________________________________________

void insert_at(Mylist* l,char* data,size_t index);
void erase_at(Mylist* l,char* out, size_t index);

// _______________________________________________________________

void print_list(Mylist* l);
int size(Mylist* l);
bool isEmpty(Mylist* l);

// _______________________________________________________________

void freelist(Mylist* l);

#endif