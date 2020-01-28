struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

int mx2(int a, int b)
{
	return a > b ? a : b;
}

int mx3(int a, int b, int c)
{
	if (a > b)
		return a > c ? a : c;
	return b > c ? b : c;
}

int height(struct s_node *n)
{
	if (!n)
		return 0;
	int h = 1 + mx2(height(n->left), height(n->right));
	return n->value = h;
}

int     helper(struct s_node *n, int mx)
{
	if (!n)
		return mx;
	int l = n->left ? n->left->value : 0;
	int r = n->right ? n->right->value : 0;
	int v = l + r + 1;
	l = helper(n->left, v);
	r = helper(n->right, v);
	return mx3(mx, l, r);
}

int     width_tree(struct s_node *n)
{
	height(n);
	return helper(n, 0);
}

/*
#include <stdlib.h>
#include <stdio.h>
typedef struct s_node t_node;
t_node *cr(int n)
{
	t_node *node = malloc(sizeof(t_node));
	node->value = n;
	node->left = node->right = NULL;
	return node;
}

int main()
{
	t_node *one = cr(1);
	one->left = cr(2);
	one->right = cr(5);
	one->left->left = cr(3);
	one->left->right = cr(4);
	one->left->right->left = cr(6);
	one->right->left = cr(7);
	one->right->right = cr(8);
	printf("%d\n", width_tree(one));

	one->left = cr(2);
	one->left->left = cr(4);
	one->left->left->left = cr(5);
	one->left->left->left->right = cr(8);
	one->left->left->right = cr(6);
	one->left->right = cr(7);
	one->left->right->left = cr(9);
	one->left->right->left->left = cr(11);
	one->left->right->left->right = cr(12);
	one->left->right->right = cr(10);
	one->left->right->left->right = cr(13);
	one->right = cr(3);
	printf("%d\n", width_tree(one));

	t_node *ten = cr(10);
	ten->left = cr(12);
	printf("%d\n", width_tree(ten));

	t_node *tfive = cr(25);
	tfive->left = cr(33);
	tfive->left->left = cr(12);
	tfive->left->right = cr(9);
	tfive->left->right->left = cr(3);
	printf("%d\n", width_tree(tfive));

	ten->left = ten->right = NULL;
	printf("%d\n", width_tree(ten));

	printf("%d\n", width_tree(NULL));
}*/
