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
    Node*  tail;
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

// _______________________________________________________________

void headpush(Mylist* l,char* obj)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = obj;
    newNode->next = l->head;
    l->head = newNode;

    if (l->tail == NULL)
        l->tail = newNode;

    l->size += 1;
}

void headpop(Mylist* l)
{
    if (l->head == NULL){
        printf("[ERROR]headPointerIsNULL");
        return;
    }

    Node* temp = l->head;
    l->head = l->head->next; 
    free(temp);
    
    l->size--;
}

void tailpush(Mylist* l,char* obj)
{
    Node* newNode = malloc(sizeof(Node));
    newNode->data = obj;
    newNode->next = NULL;

    if (l->head == NULL){
        l->head = newNode;
        l->tail = newNode;
    }
    else 
    {
        l->tail->next = newNode;
        l->tail = newNode;
    }
    
    l->size += 1;
}

void tailpop(Mylist* l)
{
    if (l->head == NULL){
        printf("[ERROR]tailPointerIsNULL");
        return;
    }

    if (l->head == l->tail){
        Node* temp = l->head;
        free(temp);
        l->head = NULL;
        l->tail = NULL;
    }
    else 
    {
        Node* temp = l->head;
        while (temp->next != l->tail)
                temp = temp->next;

        free(l->tail);
        l->tail = temp;
        temp->next = NULL;
    }
  
    l->size--;
}
// _______________________________________________________________

void insert_at(Mylist* l,char* data,size_t index)
{   
    if (!l) return;

    if (index == 0){
        headpush(l,data);
        return;
    }

    if(index > l->size){
        printf("IncorrectIndex");
        return;    
    }

    Node* current = l->head;
    for (size_t i = 0; i < index - 1; i++){
        if(!current) return;
    
        current = current->next;
    }

    Node* newnode = malloc(sizeof(Node));
    if(!newnode) return;

    newnode->data = data;
    newnode->next = current->next;
    current->next = newnode;

    l->size += 1;
}   

void erase_at(Mylist* l, size_t index)
{
    if (!l) return;

    if (index == 0){
        headpop(l);
        return;
    }

    if(index >= l->size){
        printf("IncorrectIndex\n");
        return;    
    }

    Node* current = l->head;
    for (size_t i = 0; i < index - 1;i++){
        if (!current) return;
        current = current->next;
    }
    Node* temp = current->next->next;
    free(current->next);
    current->next = temp;

    l->size--;
}

// _______________________________________________________________

Node* find(Mylist* l, const char* val)
{   
    Node* current = l->head;
    while (current != NULL){
        if (strcmp(current->data,val) == 0)
            return current;
        current = current->next;
    }
    return NULL;
}
char* findValue(Mylist* l, const char* val)
{   
    Node* temp = find(l,val);
    if(!temp)return NULL;
    return temp->data;
}


Node* getByIndex(Mylist* l, unsigned int index)
{
    Node* current = l->head;
    if (index > l->size) return NULL;

    for (unsigned int i = 0; i < index; i++){
        if(current == NULL)break;
        current = current->next;
    }
        
    return current;    
}
char* getValueByIndex(Mylist* l, unsigned int index)
{
    Node* temp = getByIndex(l,index);
    if (!temp) return NULL;
    return temp->data;
}

// _______________________________________________________________

void print_list(Mylist* l)
{
    if (!l) return;
    Node* current = l->head; 
    while (current != NULL){
        printf("%s", current->data);
        current = current->next;
    }
}

int size(Mylist* l)
{
    if (!l) return 0;
    return l->size;
}
bool isEmpty(Mylist* l)
{
    return l->head == NULL;
}

// _______________________________________________________________

void freelist(Mylist* l)
{
    if (!l) return;

    Node* temp;
    while (l->head){
        temp = l->head;
        l->head = l->head->next;
           
        free(temp);
    }

    l->head = NULL;
    l->size = 0;
}
