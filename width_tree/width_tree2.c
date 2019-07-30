struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

int max(int a, int b)
{
	return a > b ? a : b;
}

int height(struct s_node *n)
{
	if (!n)
		return 0;
	int a = 1 + height(n->left);
	int b = 1 + height(n->right);
	return n->value = max(a, b);
}

int helper(struct s_node *n, int mx)
{
	if (!n)
		return mx;
	int a = n->left ? n->left->value : 0;
	int b = n->right ? n->right->value : 0;
	if (1 + a + b > mx)
		mx = 1 + a + b;
	return max(helper(n->left, mx), helper(n->right, mx));
}

int     width_tree(struct s_node *n)
{
	height(n);
	return helper(n, 0);
}

/*
#include <stdlib.h>
struct s_node *cr(int v)
{
	struct s_node *res = malloc(sizeof(struct s_node));
	res->value = v;
	res->right = res->left = NULL;
	return res;
}

#include <stdio.h>
int main()
{
	struct s_node *a = cr(1);
	a->left = cr(2), a->right = cr(5);
	a->left->left = cr(3), a->left->right = cr(4), a->right->left = cr(7), a->right->right = cr(8);
	a->left->right->left = cr(6);
	printf("%d\n", width_tree(a));
	a = cr(1);
	a->left = cr(2), a->right = cr(3);
	a->left->left = cr(4), a->left->right = cr(7);
	a->left->left->left = cr(5), a->left->left->right = cr(6), a->left->right->left = cr(9), a->left->right->right = cr(10);
	a->left->left->left->right = cr(8), a->left->right->left->left = cr(11), a->left->right->left->right = cr(12), a->left->right->right->right = cr(13);
	printf("%d\n", width_tree(a));
	a = cr(10);
	a->right = cr(12);
	printf("%d\n", width_tree(a));
	a = cr(25);
	a->left = cr(33);
	a->left->left = cr(12), a->left->right = cr(9);
	a->left->right->left = cr(3);
	printf("%d\n", width_tree(a));
	a = cr(10);
	printf("%d\n", width_tree(a));
}
*/
