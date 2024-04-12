#include "binary_trees.h"

/**
 * array_to_avl - This function builds an AVL tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of element in the array.
 *
 * Return: a pointer to the root node of the created AVL tree.
 * Return NULL on failure.
 * If a value of the array is already present in the tree,
 * this value must be ignored.
 */

avl_t *array_to_avl(int *array, size_t size)
{
	unsigned int a;
	avl_t *root = NULL;

	for (a = 0; a < size; a++)
		avl_insert(&root, array[a]);

	return (root);
}
