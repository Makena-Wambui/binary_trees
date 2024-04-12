#include "binary_trees.h"

/**
 * bst_search - This function searches for a value in a BST.
 * @tree: a pointer to the root node of the BST to search.
 * @value: the value to search in the tree.
 * Return: a pointer to the node containing a value equals to value.
 * If tree is NULL or if nothing is found, your function must return NULL.
 */

bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *temp;

	temp = (bst_t *)tree;

	if (!tree)
		return (NULL);

	while (temp)
	{
		if (value == temp->n)
			return (temp);
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
	}

	return (NULL);
}
