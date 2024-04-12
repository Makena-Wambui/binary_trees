#include "binary_trees.h"

/**
 * binary_tree_is_bst - This function checks if a binary tree,
 * is a valid Binary Search Tree.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST
 * Return 0 if tree is not a valid BST.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	/**
	 * Properties of a Binary Search Tree:
	 *
	 * The left subtree of a node contains only nodes with values
	 * less than the node’s value.
	 * The right subtree of a node contains only nodes with values
	 * greater than the node’s value.
	 * The left and right subtree each must also be a binary search tree
	 * There must be no duplicate values.
	 */
	if (!tree)
		return (0);

	/**
	 * calls BST_helper to perform the actual checking,
	 * passing the root node, the minimum possible value (INT_MIN),
	 * and the maximum possible value (INT_MAX).
	 */

	return (BST_helper(tree, INT_MIN, INT_MAX));
}

/**
 * BST_helper - This function recursively checks if a binary tree,
 * is a valid Binary Search Tree.
 * @tree: A pointer to the current node being checked.
 * @min: min possible value a node in the subtree rooted at tree can have.
 * @max: max possible value a node in the subtree rooted at tree can have.
 *
 * Return: 1 if tree is a valid BST.
 * Return 0 if tree is not a valid BST.
 */

int BST_helper(const binary_tree_t *tree, int min, int max)
{
	/* NULL subtree is considered a valid BST.*/
	if (!tree)
		return (1);
	/**
	 * checks if the value of the current node (tree->n) is outside
	 * the range defined by min and max. If it is,
	 * the subtree rooted at tree is not a valid BST, so it returns 0.
	 */

	if (tree->n < min || tree->n > max)
		return (0);
	/**
	 * recursively calls BST_helper for the left subtree,
	 * updating the maximum value to tree->n - 1,
	 * and for the right subtree, updating the minimum value to tree->n + 1.
	 * This ensures that the BST property is maintained for each subtree.
	 * It returns the logical AND of the results of the recursive calls.
	 * If both the left and right subtrees are valid BSTs,
	 * the current subtree is considered a valid BST.
	 */

	return (BST_helper(tree->left, min, tree->n - 1) &&
		BST_helper(tree->right, tree->n + 1, max));
}
