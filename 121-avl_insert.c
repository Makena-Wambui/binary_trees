#include "binary_trees.h"

/**
 * bst_insert - This function inserts a value in a BST.
 * @tree: a double pointer to the root node of the BST to insert the value.
 * @value: the value to store in the node to be inserted.
 * Return: A pointer to the created node.
 * Return NULL on failure.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *temp = NULL;
	bst_t *prev = NULL;
	bst_t *new = NULL;

	if (!tree)
		return (NULL);

	if (*tree == NULL)
		return (*tree = binary_tree_node(NULL, value));

	temp = *tree;
	while (temp)
	{
		prev = temp;
		if (value < temp->n)
			temp = temp->left;
		else if (value > temp->n)
			temp = temp->right;
		else if (value == temp->n)
			return (NULL);
	}

	new = binary_tree_node(NULL, value);
	if (prev == NULL)
		prev = new;
	else if (value < prev->n)
	{
		prev->left = new;
		new->parent = prev;
	}
	else
	{
		prev->right = new;
		new->parent = prev;
	}

	return (new);
}

/**
 * avl_insert - This function inserts a value in an AVL Tree.
 * @tree: a double pointer to the root node of the AVL tree
 * for inserting the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node.
 * Return NULL on failure.
 * If the address stored in tree is NULL,
 * the created node must become the root node.
 * The resulting tree after insertion, must be a balanced AVL Tree
 */

avl_t *avl_insert(avl_t **tree, int value)
{
	/**
	 * first call bst_insert to perform standard BST insertion,
	 * which adds the new value to the tree
	 */
	avl_t *new = bst_insert(tree, value);
	int balance = 0;

	/* calculates the balance factor of the tree. */
	balance = binary_tree_balance(*tree);
	/* perform a left rotation. */
	if (balance < -1 && value > new->right->n)
		return (binary_tree_rotate_left(new));
	/* perform a right rotation.*/
	if (balance > 1 && value < new->left->n)
		return (binary_tree_rotate_right(new));
	/**
	 * perform a left rotation on the left child
	 * followed by a right rotation on the current node.
	 */
	if (balance > 1 && value > new->left->n)
	{
		new->left = binary_tree_rotate_left(new->left);
		return (binary_tree_rotate_right(new));
	}
	/**
	 * perform a right rotation on the right child
	 * followed by a left rotation on the current node.
	 */
	if (balance < -1 && value < new->right->n)
	{
		new->right = binary_tree_rotate_right(new->right);
		return (binary_tree_rotate_left(new));
	}

	return (new);
}
