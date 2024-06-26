#include "binary_trees.h"

/**
 * binary_tree_is_root - This function checks if a node is a root.
 * @node: a pointer to the node to check.
 *
 * Return: 1 if node is a root, otherwise 0.
 *
 * If node is NULL, return 0.
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	return ((!node || node->parent) ? 0 : 1);
}
