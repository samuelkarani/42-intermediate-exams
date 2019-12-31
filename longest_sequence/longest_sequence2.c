
struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int helper(struct s_node *node, int ret)
{
	struct s_node *left = node->left, *right = node->right;
	int l;
	if (left)
	{
		if (left->value - node->value == 1)
			l = helper(left, ret + 1);
		else
			l = helper(left, 1);
		ret = l > ret ? l : ret;
	}
	if (right)
	{
		if (right->value - node->value == 1)
			l = helper(right, ret + 1);
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

// #include <stdlib.h>
// #include <stdio.h>
// void one(void)
// {
// 	struct s_node seven = {.value = 7, .left = NULL, .right = NULL};
// 	struct s_node thirteen = {.value = 13, .left = NULL, .right = NULL};
// 	struct s_node six = {.value = 6, .left = &seven, .right = &thirteen};
// 	struct s_node nine = {.value = 9, .left = NULL, .right = NULL};
// 	struct s_node five = {.value = 5, .left = &six, .right = &nine};
// 	struct s_node ten = {.value = 10, .left = &five, .right = NULL};
// 	printf("%d\n", longest_sequence(&ten));
// }

// void two(void)
// {
// 	struct s_node two_a = {2, NULL, NULL};
// 	struct s_node two_b = {2, NULL, NULL};
// 	struct s_node three_a = {3, NULL, &two_a};
// 	struct s_node three_b = {3, NULL, NULL};
// 	struct s_node nine = {9, &three_b, &two_b};
// 	struct s_node four = {4, &nine, &three_a};
// 	struct s_node six = {6, NULL, NULL};
// 	struct s_node five = {5, &six, &four};
// 	printf("%d\n", longest_sequence(&five));
// }

// void three(void)
// {
// 	struct s_node eighty = {80, NULL, NULL};
// 	struct s_node sixtyone = {61, NULL, NULL};
// 	struct s_node fortyone = {41, &eighty, NULL};
// 	struct s_node fifteen = {15, &sixtyone, NULL};
// 	struct s_node thirty = {30, &fifteen, &fortyone};
// 	printf("%d\n", longest_sequence(&thirty));
// }

// void four(void)
// {
// 	struct s_node three = {3, 0, 0};
// 	struct s_node two = {2, 0, &three};
// 	struct s_node one = {1, 0, &two};
// 	struct s_node sixa = {6, 0, 0};
// 	struct s_node sixb = {6, &one, 0};
// 	struct s_node five = {1, &sixa, &sixb};
// 	printf("%d\n", longest_sequence(&five));
// }

// int main(void)
// {
// 	one();
// 	two();
// 	three();
// 	four();
// 	printf("%d\n", longest_sequence(NULL));
// 	struct s_node one = {1, NULL, NULL};
// 	printf("%d\n", longest_sequence(&one));
// }
