#include "binary_trees.h"

/**
 * binary_tree_rotate_right - This function performs a
 * right-rotation on a binary tree.
 * @tree: a pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node of the tree once rotated..
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *parent;
	binary_tree_t *temp;

	/**
	 * checks if tree is NULL or if tree does not have a left child.
	 * If either condition is true, it returns NULL, indicating failure.
	 */
	if (!tree || !tree->left)
		return (NULL);
	/* initialize temp to tree and parent to tree->parent.*/
	temp = tree;
	parent = tree->parent;

	/* tree now points to its left child, making the right child the new root.*/
	tree = tree->left;
	/* set the parent of the new root to NULL; it is now the new root.*/
	tree->parent = NULL;

	/* if new root has a right child*/
	if (tree->right)
	{
		/* updates temp->left to point to the right child of the new root.*/
		temp->left = tree->right;
		tree->right->parent = temp;
	}
	else
		temp->left = NULL;
	/* updates the parent pointer of temp to point to the new root.*/
	temp->parent = tree;
	/**
	 * sets the left child of the new root to temp,
	 * hence attaching the original root as the left child of the new root.
	 */
	tree->right = temp;
	/* If there was a parent node before the rotation*/
	if (parent)
		parent->left = tree;
	/* update parent pointer of the new root to point to the original parent.*/
	tree->parent = parent;
	return (tree);
}
