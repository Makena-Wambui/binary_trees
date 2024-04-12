#include "binary_trees.h"

/**
 * bst_remove - This function removes a node from a BST.
 * @root: a pointer to the root node of the tree where you will remove a node.
 * @value: the value to remove in the tree.
 * Once located, the node containing a value equals to value,
 * must be removed and freed.
 * If the node to be deleted has two children,
 * it must be replaced with its first in-order successor.
 * Return: a pointer to the new root node of the tree after removing value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *temp;

	temp = NULL;
	if (!root)
		return (NULL);
	/**
	 * If the value to be removed is less than the value of the current node,
	 * it recursively calls bst_remove on the left subtree.
	 */
	if (value < root->n)
		root->left = bst_remove(root->left, value);
	/* If the value to be removed is greater than the value of the current node*/
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (!root->left)
		{
			temp = root->right;
			free(root);
			return (temp);
		}
		else if (!root->right)
		{
			temp = root->left;
			free(root);
			return (temp);
		}
		/**
		 * If the current node has both left and right children,
		 * it finds the minimum value node in the right subtree
		 * using the bst_min_val function
		 */
		temp = smallest_node(root->right);
		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}
	return (root);
}

/**
 * smallest_node - This function finds the smallest node from a BST.
 * @root: a pointer to the root node of the BST.
 * Return: a pointer to the node whose value is smallest.
 */
bst_t *smallest_node(bst_t *root)
{
	/**
	 * It initializes a pointer smallest to root.
	 * It iteratively traverses the left child of min
	 * until it reaches a node with no left child (i.e., the smallest node).
	 * It returns the pointer to the smallest node.
	 */
	bst_t *smallest = root;

	while (smallest->left)
		smallest = smallest->left;

	return (smallest);
}
