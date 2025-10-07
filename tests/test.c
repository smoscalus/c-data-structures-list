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

enum init_list_iter
{
    TEST_LIST,
    TEST_ITER,
    TEST_ALL
};



/**
 * @defgroup list_tests List Tests
 * @brief Contains tests for list.c
 * 
 * NOT all functions are convered, but only the most used ones.   
 * 
 * To start this test use:
 *      enum init_list_iter TEST_LIST param
 *          or
 *      enum init_list_iter TEST_ALL param
 * 
 * These functions test core list operations.
 * @{
 */
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

/** @} */ // end of list_tests


/**
 * @defgroup iter_tests Iterator Tests
 * @brief Contains tests for list.c
 * 
 * NOT all functions are convered, but only the most used ones.   
 * 
 * To start this test use:
 *      enum init_list_iter TEST_ITER param
 *          or
 *      enum init_list_iter TEST_ALL param
 * 
 * These functions test core list operations.
 * @{
 */
    int TEST_BEGIN()
    {
        Mylist l = createList();
        headpush(&l,"hi");

        iter i = begin(&l);

        TEST_EQ_PTR(l.head,i.node); 

        return 0;
    }
    int TEST_END()
    {
        Mylist l = createList();
        headpush(&l,"hi");
        headpush(&l,"world");
        
        iter i = end(&l);

        TEST_EQ_PTR(l.tail,i.node); 

        return 0;
    }


/** @} */ // end of iter_tests


int TEST_LIST_FUNC()
{
    int alltest = 0;
    alltest += TEST_HEAD_PUSH_POP();
    alltest += TEST_TAIL_PUSH_POP();
    alltest += TEST_INSERT_AT();
    alltest += TEST_FIDN_FINDVALUE();
    alltest += TEST_GETVALUEBY_GETBY_INDEX();
    alltest += TEST_SIZE();
    alltest += TEST_ISEMPTY();
    alltest += TEST_FREELIST();
    return alltest;
}
int TEST_ITER_FUNC()
{
    int alltest = 0;
    alltest += TEST_BEGIN();
    alltest += TEST_END();

    return alltest;
}
int main()
{   
    enum init_list_iter head = TEST_ITER;
    unsigned int alltest = 0;
    switch (head)
    {
    case   TEST_LIST:
        alltest += TEST_LIST_FUNC();
        break;
    case   TEST_ITER:
        alltest += TEST_ITER_FUNC();
        break;    
    case   TEST_ALL:
        
        break; 
    }

    
    printf("%d/10 didn't pass the tests", alltest);
    return 1;
}