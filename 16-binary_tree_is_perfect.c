#include "binary_trees.h"

/**
 * binary_tree_is_perfect - This function checks if a binary tree is perfect.
 * @tree: a pointer to the root node of the tree to check.
 *
 * If tree is NULL, return 0.
 * If tree is not perfect, return 0.
 *
 * Return: 1 if the tree is perfect.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	/**
	 * A perfect binary tree: All nodes have exactly two children,
	 * and all leaf nodes are at the same level.
	 * Symmetrical and balanced.
	 */

	size_t number_of_nodes = 0;
	size_t tree_height = 0;
	size_t expo = 0;

	if (!tree)
		return (0);

	/* empty tree */
	if (!tree->right && !tree->left)
		return (1);

	/* calculate the number of nodes in the tree */
	number_of_nodes = binary_tree_size(tree);
	/* calculate the height of the tree */
	tree_height = binary_tree_height(tree);

	/**
	 * check if the actual number of nodes in the tree,
	 * matches the expected number for a perfect binary tree.
	 * The expected number of nodes in a perfect binary tree with height h
	 * is given by (2^{h+1} - 1).
	 */
	expo = (size_t)exponential(2, tree_height + 1);
	return (expo - 1 == number_of_nodes);
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
 * exponential - This function computes an expected number of nodes
 * for a perfect binary tree.
 * @x: the base.
 * @y: the power.
 * Return: x ^ y, or -1 if y is negative.
 */

int exponential(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	else
		return (x * exponential(x, y - 1));
}


/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to measure the height of.
 *
 * If tree is NULL, your function must return 0.
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
