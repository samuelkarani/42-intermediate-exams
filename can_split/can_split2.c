struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};

int count(struct s_node *n)
{
	if (!n)
		return 0;
	int c = 1 + count(n->left) + count(n->right);
   return n->value = c;
}

int helper(struct s_node *n, int c)
{
	if (!n)
		return 0;
	if (n->value * 2 == c)
		return 1;
	if (helper(n->left, c) || helper(n->right, c))
		return 1;
	return 0;
}

int     can_split(struct s_node *n)
{
	if (!n)
		return 0;
	int c = count(n);
	if (c % 2 == 1)
		return 0;
	return helper(n, c);
}

/*
#include <stdlib.h>
struct s_node *c(int n)
{
	struct s_node *res = malloc(sizeof(struct s_node));
	res->value = n;
	res->left = res->right = 0;
	return res;
}

#include <stdio.h>
int main()
{
	struct s_node *a = c(28);
	a->left = c(51);
	a->left->left = c(26);
	a->left->left->left = c(76);
	a->left->right = c(48);
	a->left->left->right = c(13);
	printf("%d\n", can_split(a));

	a = c(30);
	a->left = c(15);
	a->right = c(41);
	a->left->left = c(41);
	a->right->left = c(80);
	printf("%d\n", can_split(a));



	a = c(10);
	a->right = c(12);
	printf("%d\n", can_split(a));

	a = c(5);
	a->left = c(1);
	a->right = c(6);
	a->right->left = c(7);
	a->right->right = c(4);
	a->right->left->left = c(3);
	a->right->left->right = c(2);
	a->right->right->right = c(8);
	printf("%d\n", can_split(a));

	a = c(1);
	printf("%d\n", can_split(a));

	printf("%d\n", can_split(0));
}
*/
