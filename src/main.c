#include "stdio.h"




struct Node{
    struct Node* p;   
    char* node;
};
typedef struct
{
    char* head;
    unsigned int size;
}Mylist;

Mylist createList()
{
    Mylist l;
    l.size = 0;
    l.head = NULL;
    return l;
}


int main()
{
    return 1;
}