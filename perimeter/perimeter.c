#include <stdio.h>
struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

int count;

void print(int value)
{
	if (count)
		printf(" ");
	printf("%d", value);
	count++;
}

void print_left(struct s_node *root)
{
	if (!root || (!root->left && !root->right))
		return ;
	print(root->value);
	print_left(root->left);
}

void print_right(struct s_node *root)
{
	if (!root || (!root->left && !root->right))
		return ;
	print_right(root->right);
	print(root->value);
}

void print_node(struct s_node *root)
{
	if (!root)
		return ;
	if (!root->right && !root->left)
		print(root->value);
	print_node(root->left);
	print_node(root->right);
}

void perimeter(struct s_node *root)
{
	if (!root)
		return ;
	count = 0;
	print(root->value);
	print_left(root->left);
	print_node(root);
	print_right(root->right);
}

#include <stdlib.h>
#include "stdio.h"
#include "stdlib.h"
struct s_node *new(int value)
{
	struct s_node *n = malloc(sizeof(struct s_node));
	n->value = value;
	n->left = NULL;
	n->right = NULL;
	return n;
}

int main (void)
{
	struct s_node *node = new(92);

	node->left = new(85);
	node->right = new(26);

	node->left->left = new(79);

	//node->left->left->left = new(200);
	//node->left->left->left->left = new(300);
	node->left->left->right = new(10);

	node->left->left->right->left = new(39);

	node->left->left->right->left->left = new(35);

	node->left->left->right->left->left->left = new(96);

	node->right->right = new(64);

	node->right->right->left = new(40);
	node->right->right->right = new(78);

	node->right->right->left->left = new(88);
	node->right->right->left->right = new(10);

	node->right->right->left->left->left = new(12);
	node->right->right->left->left->right = new(55);

	node->right->right->left->left->left->left = new(58);

	node->right->right->left->left->right->right = new(41);
	node->right->right->left->left->right->left = new(58);

	node->right->right->left->right->left = new(52);
	node->right->right->left->right->right = new(87);

	node->right->right->left->right->left->left = new(22);
	node->right->right->left->right->left->right = new(35);

	node->right->right->left->right->right->right = new(31);

	node->right->right->right->left = new(2);
	node->right->right->right->right = new(85);

	node->right->right->right->left->left = new(33);
	node->right->right->right->left->right = new(11);

	node->right->right->right->left->left->right = new(55);

	node->right->right->right->left->right->left = new(99);

	node->right->right->right->right->right = new(51);
	//node->right->right->right->right->right->left = new(100);

	perimeter(node);
	return 0;
}
