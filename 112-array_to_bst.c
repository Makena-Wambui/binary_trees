#include "binary_trees.h"

/**
 * array_to_bst - This function builds a BST from an array.
 * @array: pointer to the first element of the array to be converted.
 * @size: the number of elements in the array.
 * Return: A pointer to the root node of the created BST
 * Return NULL on failure.
 * If a value of the array is already present in the tree,
 * this value must be ignored.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	unsigned int a;
	bst_t *root = NULL;

	for (a = 0; a < size; a++)
		bst_insert(&root, array[a]);

	return (root);
}
