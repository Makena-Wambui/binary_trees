#include "binary_trees.h"

/**
 * binary_tree_balance - This function measures the balance factor
 * of a binary tree.
 * @tree: pointer to the root node of the tree to measure the
 * balance factor of.
 *
 * If tree is NULL, return 0.
 * Return: the balance factor(an integer)
 *
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	/**
	 * The balance factor of a binary tree is the difference between
	 * the height of its left subtree and the height of its right subtree.
	 * If the tree is perfectly balanced i.e., the heights of the left
	 * and right subtrees differ by at most 1), the balance factor will be 0.
	 *
	 * If the left subtree is taller, the balance factor will be positive.
	 * If the right subtree is taller, the balance factor will be negative.
	 */

	int height_left;
	int height_right;

	/* an empty tree is balanced. */
	if (!tree)
		return (0);

	/* If the left child does not exist, sets height_left to -1.*/
	height_left = tree->left ? (int)binary_tree_height(tree->left) : -1;

	/* Do the same to the right child. */
	height_right = tree->right ? (int)binary_tree_height(tree->right) : -1;

	return (height_left - height_right);
}


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

	if (!tree)
		return (0);

	height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_left > height_right ? height_left : height_right);
}
