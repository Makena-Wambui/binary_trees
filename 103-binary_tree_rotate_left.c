#include "binary_trees.h"

/**
 * binary_tree_rotate_left - This function performs a
 * left-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated..
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *parent;
	binary_tree_t *temp;

	/**
	 * checks if tree is NULL or if tree does not have a right child.
	 * If either condition is true, it returns NULL, indicating failure.
	 */
	if (!tree || !tree->right)
		return (NULL);
	/* initialize temp to tree and parent to tree->parent.*/
	temp = tree;
	parent = tree->parent;

	/* tree now points to its right child, making the right child the new root.*/
	tree = tree->right;
	/* set the parent of the new root to NULL; it is now the new root.*/
	tree->parent = NULL;

	/* if new root has a left child*/
	if (tree->left)
	{
		/* updates tmp->right to point to the left child of the new root.*/
		temp->right = tree->left;
		tree->left->parent = temp;
	}
	else
		temp->right = NULL;
	/* updates the parent pointer of temp to point to the new root.*/
	temp->parent = tree;
	/**
	 * sets the left child of the new root to temp,
	 * hence attaching the original root as the left child of the new root.
	 */
	tree->left = temp;
	/* If there was a parent node before the rotation*/
	if (parent)
		parent->right = tree;
	/* update parent pointer of the new root to point to the original parent.*/
	tree->parent = parent;
	return (tree);
}
