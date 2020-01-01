
struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int helper(struct s_node *node, int n)
{
	int ret = n;
	struct s_node *left = node->left, *right = node->right;
	int l;
	if (left)
	{
		if (left->value - node->value == 1)
			l = helper(left, n + 1);
		else
			l = helper(left, 1);
		ret = l > ret ? l : ret;
	}
	if (right)
	{
		if (right->value - node->value == 1)
			l = helper(right, n + 1);
		else
			l = helper(right, 1);
		ret = l > ret ? l : ret;
	}
	return ret;
}

int longest_sequence(struct s_node *node)
{
	if (!node)
		return 0;
	return helper(node, 1);
}

#include <stdio.h>
#include <stdlib.h>
typedef struct s_node t_node;
t_node *cr(int value)
{
	t_node *node = malloc(sizeof(t_node));
	node->value = value;
	node->right = node->left = NULL;
	return node;
}

int main()
{
	t_node *ten = cr(10);
	ten->left = cr(5);
	ten->left->left = cr(6);
	ten->left->right = cr(9);
	ten->left->left->left = cr(7);
	ten->left->left->right = cr(13);
	printf("%d\n", longest_sequence(ten));

	t_node *five = cr(5);
	five->left = cr(6);
	five->right = cr(4);
	five->right->left = cr(9);
	five->right->right = cr(3);
	five->right->left->left = cr(3);
	five->right->left->right = cr(4);
	five->right->right->right = cr(2);
	printf("%d\n", longest_sequence(five));

	t_node *thirty = cr(30);
	thirty->left = cr(15);
	thirty->right = cr(41);
	thirty->left->left = cr(61);
	thirty->right->left = cr(80);
	printf("%d\n", longest_sequence(thirty));
	printf("%d\n", longest_sequence(NULL));
}
