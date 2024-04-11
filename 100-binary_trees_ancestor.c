#include "binary_trees.h"

/**
 * binary_trees_ancestor - This function finds the LCA of two nodes.
 *
 * @first: a pointer to the first node whose common ancestor we are finding.
 * @second: a pointer to the second node whose common ancestor we are finding.
 *
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 * If no common ancestor was found, your function must return NULL.
 *
 */

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	 /* The LCA is the deepest node that is an ancestor of both the given nodes.*/
	size_t depth_of_first_node;
	size_t depth_of_second_node;

	if (!first || !second)
		return (NULL);
	/* find the depth of each node. */
	depth_of_first_node = binary_tree_depth(first);
	depth_of_second_node = binary_tree_depth(second);

	/**
	 * adjusts the pointers to the nodes so that they are at the same depth.
	 * Then traverses up the tree from both nodes simultaneously
	 * until it finds the LCA.
	 * If the depth of the first node is greater,
	 * it moves the first node pointer up (first = first->parent)
	 * and decrements the depth (depth_first--).
	 * If the depth of the second node is greater,
	 * it does the same for the second node.
	 * Once both nodes are at the same depth,
	 * it traverses up the tree from both nodes simultaneously.
	 */
	while (depth_of_first_node > depth_of_second_node)
	{
		first = first->parent;
		depth_of_first_node--;
	}
	while (depth_of_second_node > depth_of_first_node)
	{
		second = second->parent;
		depth_of_second_node--;
	}
	while (first && second)
	{
		if (first == second)
			return ((binary_tree_t *)first);
		first = first->parent;
		second = second->parent;
	}
	return ((binary_tree_t *)first);
}

/**
 * binary_tree_depth - This function measures the depth
 * of a node in a binary tree.
 * @tree: pointer to the node whose depth we are calculating.
 * If tree is Null, return 0.
 * Return: depth of the node.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	if (!tree)
		return (0);
	while (tree->parent)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
