#include "binary_trees.h"

/**
 * bst_insert - This function inserts a value in a BST.
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: A pointer to the created node.
 * Return NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *prev = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		prev = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (prev == NULL)
		prev = new;
	else if (value < prev->n)
	{
		prev->left = new;
		new->parent = prev;
	}
	else
	{
		prev->right = new;
		new->parent = prev;
	}

	return (new);
}
