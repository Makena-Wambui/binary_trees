#include "binary_trees.h"

/**
 * binary_tree_is_full - This function checks if a binary tree is full.
 * @tree: a pointer to the root node of the tree to check.
 *
 * If tree is NULL, return 0.
 * If the tree is not full, return 0.
 *
 * Return: 1 if the tree is full.
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	/**
	 * A full binary tree has either zero or two child nodes for each node..
	 *
	 * It does not have any nodes that have only one child node.
	 */

	if (!tree)
		return (0);

	/* empty tree. */
	if (!tree->right && !tree->left)
		return (1);

	/**
	 * Recursive call to the function to check whether the
	 * right and left subtrees are full
	 */
	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
