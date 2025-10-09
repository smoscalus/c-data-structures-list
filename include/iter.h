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
 * @note this func behaves the same as @ref begin() but returns the last node instead of the first. 
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

/**
 * @brief A sugar function for easier usage of `next()`.
 *
 * This function provides a simplified interface 
 * to easily get the value
 * 
 * @param it pointer to the iterator.
 * @return Pointer to the data of the next node or 
 * NULL if the iterator is invalid or at the end of the list.
 * 
 * @note This function modifies the iterator in place.
 * @warning After using this function, ensure the iterator is still valid.
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * char* res = nextvalue(&i);// now res == l.head->next->data
 */
char* nextvalue(iter* it);


/**
 * @brief Get data of the current node.
 *
 * This function returns current node's data.
 * 
 * @param it pointer to the iterator.
 * @return current node's data or NULL if iterator is uninitialized
 * 
 * @note This function does not modify the iterator.
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * char* res = get(&i); now res == l.head->data
 */
char* get(iter* it);


/**
 * @brief Reset the iterator.
 * 
 * This function moves the iterator to the head node.
 * 
 * @param it pointer to the iterator.
 * @param l pointer on the list.
 * 
 * @note Prints an error message to the console if list is uninitialized
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * next(&i); // now i.node->data == "hi"
 * reset(&i,&l); // now i.node->data == "world"
 */
void reset(iter* it, Mylist* l);


/**
 * @brief Compare two iterators.
 * 
 * This function compares data of two iterators.
 * 
 * @param it1 pointer to the first iterator.
 * @param it1 pointer to the second iterator.
 * @return true(1) if the iterators are equal, or false(0) if they are not equal 
 * 
 * @note return false if one of the iterators is uninitialized.
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * iter j = end(&l); 
 * 
 * int res = equals(&i,&j); now res == 0; i != j
 */
bool equals(iter* it1, iter* it2);



/**
 * @brief Check for the next node.
 * 
 * This function checks the next node. 
 * 
 * @param it pointer to the iterator
 * @return true(1) if there is a next node, or false(0) otherwise.
 * 
 * @note return false if it is uninitialized.
 * 
 * @example
 * Mylist l = createList();
 * headpush(&l,"hi");
 * headpush(&l,"world");
 * iter i = begin(&l);
 * int res = hasNext(&i); res == true(1)
 */
bool hasNext(iter* it);

#endif