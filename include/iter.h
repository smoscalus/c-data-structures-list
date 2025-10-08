#ifndef ITER_H 
#define ITER_H

#include "list.h"
#include <stdbool.h>

typedef struct
{
    Node* node;
}iter;


/**
 * @brief Initializes an iterator on first node.
 *
 * This function Initializes iterator for the given list.
 *
 * @param l pointer on the list.
 * @return Iterator pointing to the first node, or NULL if the list is uninitialized.
 *
 * @note If the list has not been initialized, the function returns NULL.
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * iter i = begin(&l);
 */
iter begin(Mylist* l);
/**
 * @brief Initializes an iterator on last node.
 *
 * This function Initializes iterator for the given list.If the list
 * has not been initialized, the function returns NULL.
 *
 * @param l pointer on the list.
 * @return Iterator pointing to the last node, or NULL if the list is uninitialized.
 *
 * @note this func behaves the same as @ref begin() but feturns the last node instead of the first. 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * iter i = end(&l);
 */
iter end(Mylist* l);

// _______________________________________________________________

/**
 * @brief moves the iterator to next node.
 *
 * Advances the iterator to the next node in the list. 
 * If iterator has not been initialized or already points past the end,
 * the function doesn't do anything   
 *
 * @param it pointer to the iterator.
 *
 * @note This function modifies the iterator in place.
 * @warning After using this function, ensure the iterator is still valid.
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * next(&i); // now i.node->data == "hi"
 */
void next(iter* it);
char* nextvalue(iter* it);

char* get(iter* it);

// _______________________________________________________________

void reset(iter* it, Mylist* l);
bool equals(iter* it1, iter* it2);

// _______________________________________________________________

bool hasNext(iter* it);

#endif