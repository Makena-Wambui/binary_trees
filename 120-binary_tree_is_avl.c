#include "binary_trees.h"

/**
 * binary_tree_is_avl - This function checks if a binary tree is a
 * valid AVL tree.
 * @tree: pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid AVL tree.
 * Return 0 otherwise.
 * If tree is NULL, return 0.
 */

int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	/**
	 * calls avl, pass the root node,
	 * the minimum possible value (INT_MIN),
	 * and the maximum possible value (INT_MAX).
	 */

	return (avl(tree, INT_MIN, INT_MAX));
}

/**
 * avl - This is a helper function that checks if a binary tree is an avl tree.
 * @tree: A pointer to the current node being checked.
 * @minimum: The minimum value allowed for a node in the tree.
 * @maximum: The maximum value allowed for a node in the tree.
 *
 * Return: 1 if the subtree rooted at tree is an AVL tree.
 * Return 0 otherwise.
 */

int avl(const binary_tree_t *tree, int minimum, int maximum)
{
	int path_left;
	int path_right;

	/* an empty subtree is an AVL tree.*/
	if (!tree)
		return (1);

	/**
	 * It checks if the value of the current node (tree->n)
	 * is within the range defined by minimum and maximum.
	 * If it's not, it returns 0.
	 */
	if (tree->n < minimum || tree->n > maximum)
		return (0);
	/**
	 * It calculates the height of the left and right subtrees of the
	 * current node using the binary_tree_height function.
	 */
	path_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	path_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	/**
	 * checks if the absolute difference in height between the left and
	 * right subtrees is greater than 1.
	 * If it is, the subtree is not balanced, and it returns 0.
	 */
	if (abs(path_left - path_right) > 1)
		return (0);

	return (avl(tree->left, minimum, tree->n - 1) &&
		avl(tree->right, tree->n + 1, maximum));
}

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 *
 * Return: height of the tree.
 * Return 0 if tree is NULL.
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
