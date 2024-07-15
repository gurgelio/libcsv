#ifndef ROW_H
#define ROW_H
#include <stddef.h>

typedef struct
{
  void *items;
  int size, capacity, itemSize;
} Array;

/**
 * Finds a string inside an Array of char *
 *
 * @param array The array to be searched
 * @param str The string to be found
 *
 * @returns first index of the searched string, and -1 if not found
 */
int arrayFindString(Array *array, char *str);

/**
 * Creates a new Array
 *
 * @param itemSize Size of the type to be stored in the array
 *
 * @returns an empty Array
 */
Array arrayNew(int itemSize);

/**
 * Gets the location of the value in the array
 *
 * @param array The array to be accessed
 * @param index The index of the value
 *
 * @throw When index is negative or greater than the array's size
 * @returns The address to the value
 */
void *arrayAt(Array *array, int index);

/**
 * Prints the array to a string
 * Should only be used with an array of char *
 *
 * @param array The array to be printed
 *
 * @returns String of the elements separated with ','
 */
char *arrayToString(Array *array);

/**
 * Adds an item to the array
 *
 * @param array The array to be appended
 * @param item Address to the item to be added
 *
 * @returns void
 */
void arrayAppend(Array *array, void *item);

/**
 * Removes an item from the array
 *
 * @param array The array to be changed
 * @param index The index of the item to be removed
 *
 * @returns void
 */
void arrayRemove(Array *array, int index);

#endif