#include "binary_trees.h"

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height of.
 *
 * If tree is NULL, your function must return 0
 *
 * Return: tree's height.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

	/**
	 * (First line)
	 * This line checks if the left child of the current node (tree) exists.
	 * If it does, it recursively calculates the height of the left subtree,
	 * by calling binary_tree_height(tree->left),
	 * and adds 1 (to account for the current level).
	 * Otherwise, it sets height_left to 0.
	 *
	 * (Second line)
	 * Calculates height of the right subtree in the same way.
	 *
	 * (Third line)
	 * The function returns the max height between the left and right subtrees.
	 *
	 */

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
