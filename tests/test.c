#include "../include/list.h"
#include "../include/iter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main()
{
    Mylist l = createList();
    headpush(&l,"hi");
    headpush(&l,"priv");
    headpush(&l,"wirld");
    headpush(&l,"world");

    for (iter i = begin(&l);hasNext(&i);next(&i)){
        printf("%s \n",i.node->data);
    }

    headpop(&l);  

    printf("___________________________\n");

    for (iter i = begin(&l);hasNext(&i);next(&i)){
        printf("%s \n",i.node->data);
    }

    printf("___________________________\n");
    Node* temp = find(&l, "priv");
    printf("%s \n%s \n", temp->data, findValue(&l,"priv"));

    printf("___________________________\n");

    headpush(&l,"wirld");
    headpush(&l,"world");

    Node* temp2 = getByIndex(&l,2);
    printf("%s \n%s \n", temp2->data, getValueByIndex(&l,2));

    printf("___________________________\n");


    printf("%d \n", isEmpty(&l));
    
    return 1;
}