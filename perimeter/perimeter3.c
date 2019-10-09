#include <stdio.h>

struct s_node {
                int	value;
                struct s_node *right;
                struct s_node *left;
};

void print_left(struct s_node *root)
{
	if (root->left || root->right)
		printf(" %d", root->value);
	if (root->left)
		print_left(root->left);
}

void print_leaves(struct s_node *root)
{
	if (!root->left && !root->right)
		printf(" %d", root->value);
	if (root->left)
		print_leaves(root->left);
	if (root->right)
		print_leaves(root->right);
}

void print_right(struct s_node *root)
{
	if (root->right)
		print_right(root->right);
	if (root->left || root->right)
		printf(" %d", root->value);
}

void perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		if (root->left)
			print_left(root->left);
		if (root->left || root->right)
			print_leaves(root);
		if (root->right)
			print_right(root->right);
	}
		printf("\n");
}

/*
#include <stdlib.h>
struct s_node *cr(int v)
{
	struct s_node *node = malloc(sizeof(struct s_node));
	node->value = v;
	node->left = node->right = NULL;
	return node;
}

int main()
{
	perimeter(0);
	struct s_node *a = cr(92);
	perimeter(a);
	a->left = cr(85);
	a->right = cr(26);
	perimeter(a);
	a->left->left = cr(79);
	a->left->left->right = cr(10);
	a->left->left->right->left = cr(39);
	a->left->left->right->left->left = cr(35);
	a->left->left->right->left->left->left = cr(96);
	a->right->right = cr(64);
	a->right->right->left = cr(40);
	a->right->right->left->left = cr(88);
	a->right->right->left->left->left = cr(12);
	a->right->right->left->left->left->left = cr(58);
	a->right->right->left->left->right = cr(55);
	a->right->right->left->left->right->left = cr(58);
	a->right->right->left->left->right->right = cr(41);
	perimeter(a);
	a->right->right->left->right = cr(10);
	a->right->right->left->right->left = cr(52);
	a->right->right->left->right->left->left = cr(22);
	a->right->right->left->right->left->right = cr(35);
	a->right->right->left->right->right = cr(87);
	a->right->right->left->right->right->right = cr(31);
	a->right->right->right = cr(78);
	a->right->right->right->left = cr(2);
	a->right->right->right->left->left = cr(33);
	a->right->right->right->left->left->right = cr(55);
	a->right->right->right->left->right = cr(11);
	a->right->right->right->left->right->left = cr(99);
	a->right->right->right->right = cr(85);
	a->right->right->right->right->right = cr(51);
	perimeter(a);
}
*/
