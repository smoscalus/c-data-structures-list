#include "../include/list.h"
#include "../include/iter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1

int main()
{
    Mylist l = createList();
    // headpush(&l,"hi");
    // headpush(&l,"priv");
    // headpush(&l,"wirld");
    // headpush(&l,"world");


    iter it = begin(&l);
    char* val;
    while((val = next(&it)) != NULL)
    {
        printf("%s \n", val);
    }


    return 1;
}