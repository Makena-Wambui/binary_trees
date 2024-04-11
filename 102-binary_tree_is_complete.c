#include "binary_trees.h"

/**
 * binary_tree_is_complete - This function checks if a binary tree is complete.
 * @tree: a pointer to the root node of the tree to check.
 *
 * If tree is NULL, your function must return 0.
 * If the tree is not complete, return 0.
 * Return: 1 if the tree is complete
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	/**
	 * A complete binary tree is a tree in which every level,
	 * except possibly the last, is completely filled,
	 * and all nodes are as far left as possible.
	 */
	size_t size;

	if (!tree)
		return (0);
	/* Calculates the sze of the tree. */
	size = binary_tree_size(tree);

	/**
	 * call complete_helper to perform the actual checking.
	 * Pass the root node, index 0 and the tree's size.
	 */
	return (complete_helper(tree, 0, size));
}

/**
 * complete_helper - This is a helper function that checks
 * if a binary tree is complete.
 *
 * @tree: a pointer to the root node of the tree to check.
 * @index: The index of the current node in a complete binary tree,
 * (assuming the root node has index 0).
 *
 * @size: total number of nodes in the binary tree.
 *
 * If the tree is not complete, return 0.
 * If the tree is NULL, return 0.
 * Return: 1 if the tree is complete.
 */
int complete_helper(const binary_tree_t *tree, size_t index, size_t size)
{
	/* a NULL node does not violate the completeness property.*/
	if (!tree)
		return (1);
	/**
	 * checks if the index is within the bounds of the total number of nodes.*
	 * If the index of the current node is greater than or equal
	 * to the size of the tree,it returns 0,
	 * indicating that the tree is not complete.
	 */
	if (index >= size)
		return (0);

	/**
	 * Recursively calls complete_helper for the left and right child nodes
	 * with updated indices:2 * index + 1 for the left child,
	 * 2 * index + 2 for the right child, and the same size.
	 * Returns the logical AND of the results of the recursive calls.
	 * If both the left and right subtrees are complete,
	 * the current subtree is considered complete.
	 */
	return (complete_helper(tree->left, 2 * index + 1, size) &&
		complete_helper(tree->right, 2 * index + 2, size));
}

/**
 * binary_tree_size - This function measures the size of a binary tree.
 * @tree: a pointer to the root node of the tree.
 *
 * If tree is NULL, return 0.
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
