#include "binary_trees.h"

/**
 * binary_tree_uncle - This function finds the uncle of a node.
 * @node: a pointer to the node whose uncle we are finding.
 *
 * Return: pointer to the uncle node.
 *
 * If node is NULL, return NULL.
 * Return NULL, if the parent is NULL.
 * If node has no uncle, return NULL.
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	/* call this function to find the node's parent's sibling */
	return (binary_tree_sibling(node->parent));
}

/**
 * binary_tree_sibling - This function finds the sibling of a node.
 * @node: pointer to the node whose sibling we are finding.
 *
 * Return: pointer to the sibling node.
 *
 *
 * If the node is NULL, return NULL.
 * Return NULL, if the parent is NULL
 * Return NULL, if the node has no siblings.
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);

	return (node->parent->left);
}
