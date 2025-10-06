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


Mylist init_TEST_LIST()
{
    Mylist l = createList();
    headpush(&l,"hi");
    headpush(&l,"hello");
    headpush(&l,"by");
    headpush(&l,"world");
    return l;
}


int TEST_HEAD_PUSH_POP()
{
    Mylist l = init_TEST_LIST();
    char arrr[N];
    headpop(&l, arrr);
    TEST_EQ_STR("world",arrr);

    headpop(&l, arrr);
    TEST_EQ_STR("by",arrr);

    headpop(&l, arrr);

    freelist(&l);
    return 0;
}
int TEST_TAIL_PUSH_POP()
{
    Mylist l = init_TEST_LIST();
    tailpush(&l,"hello");
    tailpush(&l,"world");

    char arr[N];
    tailpop(&l, arr);
    TEST_EQ_STR("world",arr);

    tailpop(&l, arr);
    TEST_EQ_STR("hello",arr);

    tailpop(&l, arr);

    freelist(&l);
    return 0;
}
int TEST_INSERT_AT()
{
    Mylist l = init_TEST_LIST();

    char out[N]; 
    insert_at(&l,"hello",2);    
    erase_at(&l,out,3);
    TEST_EQ_STR("hello",out);

    erase_at(&l,out,3);
    TEST_EQ_STR("hi",out);

    printf("___Here_must_be_Error___\n");
    erase_at(&l,out,5);

    freelist(&l);
    return 0;
}
int TEST_FIDN_FINDVALUE()
{
    Mylist l = init_TEST_LIST();

    Node* temp = find(&l,"hello");
    TEST_EQ_STR("hello",temp->data);

    char* res = findValue(&l,"hello");
    TEST_EQ_STR("hello",res);

    res = findValue(&l,"hedo");
    TEST_EQ_PTR(NULL,res);

    freelist(&l);
    return 0;
}
int TEST_GETVALUEBY_GETBY_INDEX()
{
    Mylist l = init_TEST_LIST();

    Node* temp = getByIndex(&l,2);     
    TEST_EQ_STR("hello",temp->data);

    char* res = getValueByIndex(&l,2);
    TEST_EQ_STR("hello",res);

    res = getValueByIndex(&l,5);
    TEST_EQ_PTR(NULL,res);

    freelist(&l);
    return 0;
}
int TEST_SIZE()
{
    Mylist l = init_TEST_LIST();

    TEST_EQ_INT(4,l.size);

    freelist(&l);
    return 0;
}
int TEST_ISEMPTY()
{
    Mylist l = createList();
    int res = isEmpty(&l);
    TEST_EQ_INT(1,res);

    Mylist l1 = init_TEST_LIST();
    res = isEmpty(&l1);
    TEST_EQ_INT(0,res);

    return 0;
}
int TEST_FREELIST()
{
    Mylist l = init_TEST_LIST();
    freelist(&l);
    TEST_EQ_PTR(NULL,l.head);

    return 0;
}


int main()
{   
    unsigned int alltest = 0;
       alltest += TEST_HEAD_PUSH_POP();
       alltest += TEST_TAIL_PUSH_POP();
       alltest += TEST_INSERT_AT();
       alltest += TEST_FIDN_FINDVALUE();
       alltest += TEST_GETVALUEBY_GETBY_INDEX();
       alltest += TEST_SIZE();
       alltest += TEST_ISEMPTY();
       alltest += TEST_FREELIST();
    
    printf("%d/8 didn't pass the tests", alltest);
    return 1;
}