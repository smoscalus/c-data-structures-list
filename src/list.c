#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

#define ERROR_CHAR '\0'

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

char* getAt(Mylist* l, int index)
{
    if (index > l->size){
        printf("[ERROR]IndexMoreThanSize_incorrect_index");
        return ERROR_CHAR;
    }
    for (int i = 0; i <= index; i++){
        l->head = l->head->next;
        if(l->head == NULL){
            printf("[ERROR]headPointerIsNULL_incorrect_index");
            break;
        }
    }
        
    return l->head->data;    
}


bool isEmpty(Mylist* l)
{
    return l->head == NULL;
}
