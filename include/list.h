#ifndef LIST_H
#define LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>
#include "export.h"

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

API Mylist createList();

API void headpush(Mylist* l,char* data);
API void headpop(Mylist* l,char* out);


API void tailpush(Mylist* l,char* data);
API void tailpop(Mylist* l,char* out);

// _______________________________________________________________

API Node* find(Mylist* l, const char* val);
API char* findValue(Mylist* l, const char* val);


API Node* getByIndex(Mylist* l, unsigned int index);
API char* getValueByIndex(Mylist* l, unsigned int index);

// _______________________________________________________________

API void insert_at(Mylist* l,char* data,size_t index);
API void erase_at(Mylist* l,char* out, size_t index);

// _______________________________________________________________

API void print_list(Mylist* l);
API int size(Mylist* l);
API bool isEmpty(Mylist* l);

// _______________________________________________________________

API void freelist(Mylist* l);

#ifdef __cplusplus
}
#endif

#endif