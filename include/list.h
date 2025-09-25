#ifndef LIST_H
#define LIST_H

typedef struct Node{
    char* data;
    struct Node* next; 
}Node;

typedef struct
{
    Node* head;
    unsigned int size;
}Mylist;


#endif