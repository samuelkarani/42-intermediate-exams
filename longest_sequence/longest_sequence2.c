struct s_node
{
        int value;
        struct s_node *left;
        struct s_node *right;
};


int helper(struct s_node *root, int ret)
{
	if (!root)
		return ret;
	int l, r;
	struct s_node *right = root->right, *left = root->left;
	if (left)
	{
		if (root->value - left->value == -1)
			l = helper(left, ret + 1);
		else
			l = helper(left, 1);
		ret = ret > l ? ret : l;
	}
	if (right)
	{
		if (root->value - right->value == -1)
			r = helper(right, ret + 1);
		else
			r = helper(right, 1);
		ret = ret > r ? ret : r;
	}
	return ret;
}

int     longest_sequence(struct s_node *node)
{
	if (!node)
		return 0;
	return helper(node, 1);
}

/*
#include <stdio.h>
typedef struct s_node t_node;
int main()
{
	struct s_node seven = (t_node){7, 0, 0};
	struct s_node thirteen = (t_node){13, 0, 0};
	struct s_node nine = (t_node){9, 0, 0};
	struct s_node six = (t_node){6, &seven, &thirteen};
	struct s_node five = (t_node){5, &six, &nine};
	struct s_node ten = (t_node){10, &five, 0};
	printf("%d\n", longest_sequence(&ten));
}
*/

#include <stdlib.h>
#include <stdio.h>
void one(void)
{
	struct s_node seven = {.value = 7, .left = NULL, .right = NULL};
	struct s_node thirteen = {.value = 13, .left = NULL, .right = NULL};
	struct s_node six = {.value = 6, .left = &seven, .right = &thirteen};
	struct s_node nine = {.value = 9, .left = NULL, .right = NULL};
	struct s_node five = {.value = 5, .left = &six, .right = &nine};
	struct s_node ten = {.value = 10, .left = &five, .right = NULL};
	printf("%d\n", longest_sequence(&ten));
}

void two(void)
{
	struct s_node two_a = {2, NULL, NULL};
	struct s_node two_b = {2, NULL, NULL};
	struct s_node three_a = {3, NULL, &two_a};
	struct s_node three_b = {3, NULL, NULL};
	struct s_node nine = {9, &three_b, &two_b};
	struct s_node four = {4, &nine, &three_a};
	struct s_node six = {6, NULL, NULL};
	struct s_node five = {5, &six, &four};
	printf("%d\n", longest_sequence(&five));
}

void three(void)
{
	struct s_node eighty = {80, NULL, NULL};
	struct s_node sixtyone = {61, NULL, NULL};
	struct s_node fortyone = {41, &eighty, NULL};
	struct s_node fifteen = {15, &sixtyone, NULL};
	struct s_node thirty = {30, &fifteen, &fortyone};
	printf("%d\n", longest_sequence(&thirty));
}

void four(void)
{
	struct s_node three = {3, 0, 0};
	struct s_node two = {2, 0, &three};
	struct s_node one = {1, 0, &two};
	struct s_node sixa = {6, 0, 0};
	struct s_node sixb = {6, &one, 0};
	struct s_node five = {1, &sixa, &sixb};
	printf("%d\n", longest_sequence(&five));
}

int main(void)
{
	one();
	two();
	three();
	four();
	printf("%d\n", longest_sequence(NULL));
	struct s_node one = {1, NULL, NULL};
	printf("%d\n", longest_sequence(&one));
}
