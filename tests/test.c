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

    iter i = begin(&l);
    for (;hasNext(&i);next(&i)){
        printf("%s \n",i.node->data);
    }
    printf("%s \n",get(&i));
    reset(&i,&l);
    printf("________________________\n");
    printf("%s \n",get(&i));
    printf("%s \n",nextvalue(&i)); 
    printf("__________for______________\n");
    int j = 0;
    for(iter it = begin(&l);hasNext(&i);next(&i),j++){
        for(iter it2 = begin(&l);hasNext(&i);next(&i))
            if(equals(&it,&it2))
                printf("%s \n",it.node->data);
        printf("%d",j);
    }

               
    printf("________________________\n");
    return 1;
}