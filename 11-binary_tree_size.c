#include "binary_trees.h"

/**
 * binary_tree_size - This function measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the size of.
 *
 * If tree is NULL, the function must return 0.
 * Return: size of the tree.
 *
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
