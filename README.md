A binary tree is made up of a finite set of elements called nodes. This set either is empty or consists of a node called the root together with two binary trees, called the left and right subtrees, which are disjoint from each other and from the root. (Disjoint means that they have no nodes in common.) The roots of these subtrees are children of the root. There is an edge from a node to each of its children, and a node is said to be the parent of its children.



-------Learning Objectives---------
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

1. What is a binary tree
2. What is the difference between a binary tree and a Binary Search Tree
3. What is the possible gain in terms of time complexity compared to linked lists
4. What are the depth, the height, the size of a binary tree
5. What are the different traversal methods to go through a binary tree
6. What is a complete, a full, a perfect, a balanced binary tree

HOW TO INSERT A VALUE IN A BST
---------------------------------
Function: bst_insert:

This function inserts a value into a Binary Search Tree (BST).
It takes two parameters:
tree: A double pointer to the root node of the BST where the value will be inserted.
value: The value to be inserted into the BST.

Inside the function:
It first checks if tree is NULL. If it is, it returns NULL, indicating failure.
If the tree is empty (*tree is NULL), it creates a new node with the provided value and sets it as the root node of the tree. It then returns a pointer to the newly created node.
If the tree is not empty, it traverses the tree to find the appropriate position to insert the new value.
It starts traversing from the root node (*tree) and iterates until it finds a suitable position for the new value.
During traversal, it keeps track of the previous node (prev) to correctly link the new node.
If the value to be inserted is less than the current node's value, it moves to the left child of the current node.
If the value to be inserted is greater than the current node's value, it moves to the right child of the current node.
If the value to be inserted is equal to the current node's value, it returns NULL, indicating that duplicate values are not allowed in a BST.
Once it finds the appropriate position, it creates a new node with the provided value and links it to the tree.
If the previous node (prev) is NULL (indicating that the new node will be the new root), it updates prev to point to the new node.
If the new value is less than the value of prev, it sets the new node as the left child of prev.
If the new value is greater than the value of prev, it sets the new node as the right child of prev.
It returns a pointer to the newly inserted node.
Overall, this function inserts a value into a BST while maintaining the BST property and returns a pointer to the newly created node. If the insertion fails (due to a NULL tree pointer or duplicate value), it returns NULL.
