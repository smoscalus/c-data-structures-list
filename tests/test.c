#include "../include/list.h"
#include "../include/iter.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEST_EQ_STR(exp,act){\
    if (strcmp(exp, act) != 0){\
        printf("[FAIL] %s:%d: expected %s, got %s\n",  __FILE__, __LINE__, (exp), (act));\
        return 1;\
    }\
    else { \
        printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
    } \
    }
#define TEST_EQ_INT(exp,act){\
    if (exp != act){\
        printf("[FAIL] %s:%d: expected %d, got %d\n",  __FILE__, __LINE__, (exp), (act));\
        return 1;\
    }\
    else { \
        printf("[PASS] %s:%d\n", __FILE__, __LINE__); \
    } \
    }
#define TEST_EQ_PTR(exp,act){\
        if (exp != act){ \
            printf ("[FAIL] %s:%d: expected %p, got %p\n",  __FILE__, __LINE__, (exp), (act));\
            return 1;\
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
    char arrr[N];
    headpop(&l, arrr);
    TEST_EQ_STR("world",arrr);

    headpop(&l, arrr);
    TEST_EQ_STR("hello",arrr);

    headpop(&l, arrr);

    return 0;
}
int TEST_TAIL_PUSH_POP()
{
    Mylist l = createList();
    tailpush(&l,"hello");
    tailpush(&l,"world");

    char arr[N];
    tailpop(&l, arr);
    TEST_EQ_STR("world",arr);

    tailpop(&l, arr);
    TEST_EQ_STR("hello",arr);

    tailpop(&l, arr);
    
    return 0;
}

int main()
{   
    unsigned int alltest = 0;
       alltest += TEST_HEAD_PUSH_POP();
       alltest += TEST_TAIL_PUSH_POP();

    printf("%d/5 didn't pass the tests",alltest);
    return 1;
}