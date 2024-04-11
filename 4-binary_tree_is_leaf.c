#include "binary_trees.h"

/**
 * binary_tree_is_leaf - This function checks if a node is a leaf
 * @node: a pointer to the node to check.
 *
 * Return: 1 if node is a leaf, otherwise 0.
 *
 * If node is NULL, return 0.
 *
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	/**
	 * Let us a ternary conditional expression.
	 *
	 * !node: Evaluates to true if node is a null pointer.
	 * node->left: Evaluates to true if node has a non-null left child.
	 * node->right: Evaluates to true if node has a non-null right child.
	 * The entire expression evaluates to true if any of
	 * the three conditions is true.
	 * ? 0 : 1: the ternary operator (? :).
	 * It is a concise way to write an if-else statement.
	 * If the condition in the first part ((!node || node->left || node->right))
	 * is true, it returns 0.
	 * Otherwise (if the condition is false), it returns 1.
	 */
	return ((!node || node->left || node->right) ? 0 : 1);
}
