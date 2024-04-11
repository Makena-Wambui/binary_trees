#include "binary_trees.h"

/**
 * binary_tree_levelorder - This function goes through a binary tree,
 * using level-order traversal.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t maximum_level;
	size_t level;

	if (!tree || !func)
		return;
	/* calculate the maximum level of the binary tree using binary_tree_height.*/
	maximum_level = binary_tree_height(tree) + 1;
	/*
	 * Iterate thro each level of the tree(from level 1 to the maximum level),
	 * and call helper function for each level.
	 */
	for (level = 1; level <= maximum_level; level++)
		helper(tree, func, level);
}

/**
 * helper - This function is a helper function for level-order traversal.
 * It goes through a binary tree using post-order traversal.
 * @tree: A pointer to the current node in the binary tree.
 * @func: A pointer to the function to be called for each node.
 * @level: The current level of the tree.
 */
void helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	/**
	 * If the current level is 1, it calls the function func
	 * with the value of the current node (tree->n).
	 */
	if (level == 1)
		func(tree->n);
	else
	{
		/**
		 * If the current level is greater than 1, it recursively calls helper
		 * for the left and right child nodes with the level - 1.
		 * ensures that the function is called for nodes at the next level.
		 */
		helper(tree->left, func, level - 1);
		helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - This function measures the height of a binary tree.
 * @tree: a pointer to the root node of the tree to traverse.
 *
 * If tree is NULL, return 0.
 * Return: height of the tree.
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
