#include "binary_trees.h"
/**
 * binary_tree_nodes - this function counts the nodes with
 * at least 1 child in a binary tree.
 *
 * @tree: pointer to the root node of the tree to count the number of nodes.
 *
 * If tree is NULL, the function must return 0.
 * Return: number of nodes with at least 1 child in the tree.
 *
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (binary_tree_size(tree) - binary_tree_leaves(tree));
}

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


/**
 * binary_tree_leaves - This function counts the leaves in a binary tree.
 * @tree: a pointer to the root node of the tree to count the number of leaves.
 *
 * If tree is NULL, the function must return 0.
 *
 * Return: number of leaves.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left && !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}
