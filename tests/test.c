#include "../include/list.h"
#include "../include/iter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_EQ_STR(exp,act){\
    if (strcmp(exp, act) != 0){\
        printf("[FAIL] %s:%d: expected %s, got %s\n",  __FILE__, __LINE__, (exp), (act));\
    }\
    else { \
        printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
    } \
    }
#define TEST_EQ_INT(exp,act){\
    if (exp != act){\
        printf("[FAIL] %s:%d: expected %d, got %d\n",  __FILE__, __LINE__, (exp), (act));\
    }\
    else { \
        printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
    } \
    }
#define TEST_EQ_PTR(exp,act){\
        if (exp != act){ \
            printf ("[FAIL] %s:%d: expected %p, got %p\n",  __FILE__, __LINE__, (exp), (act));\
        }\
        else { \
            printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
        } \
    }
#define N 10

int TEST_HEAD_PUSH_POP()
{
    Mylist l = createList();
    headpush(&l,"hello");
    headpush(&l,"world");
    char* arr = malloc(N);
    headpop(&l, arr);
    TEST_EQ_STR("world",arr);

    headpop(&l, arr);
    TEST_EQ_STR("hello",arr);

    headpop(&l, arr);
    TEST_EQ_PTR(NULL,arr);
    return 1;
}



int main()
{
    printf("%d",TEST_HEAD_PUSH_POP());
    return 1;
}