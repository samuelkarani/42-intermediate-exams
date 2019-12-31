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
	int h = 1 + count(n->left) + count(n->right);
	return n->value = h;
}

int helper(struct s_node *n, int h)
{
	if (!n)
		return 0;
	if (n->value == h / 2)
		return 1;
	int l = helper(n->left, h);
	int r = helper(n->right, h);
	if (l || r)
		return 1;
	return 0;
}

int can_split(struct s_node *n)
{
	int h = count(n);
	if (h % 2 == 1)
		return 0;
	return helper(n, h);
}

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

/*
#include <stdio.h>
typedef struct s_node t_node;
int main()
{
	t_node four = (t_node){4, 0, 0};
	t_node five = (t_node){5, 0, 0};
	t_node six = (t_node){6, 0, 0};
	t_node three = (t_node){3, &four, &five};
	t_node two = (t_node){2, &three, &six};
	t_node one = (t_node){2, &two, 0};
	printf("%d\n", can_split(&one));
	printf("%d\n", can_split(&two));
	printf("%d\n", can_split(&six));
	printf("%d\n", can_split(NULL));
}
*/
