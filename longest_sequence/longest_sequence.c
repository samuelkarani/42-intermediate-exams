struct s_node
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int longest_sequence_h(struct s_node *node, int s)
{
	if (!node)
		return 0;
	if (!node->left && !node->right)
		return !s ? 1 : 0;
	int sl, sr;
	sl = sr = 0;
	if (node->left)
	{
		if (node->left->value - node->value == 1)
			sl = 1 + (!s ? 1 : 0) + longest_sequence_h(node->left, 1);
		else
			sl = longest_sequence_h(node->left, 0);
	}
	if (node->right)
	{
		if (node->right->value - node->value == 1)
			sr = 1 + (!s ? 1 : 0) + longest_sequence_h(node->right, 1);
		else
			sr = longest_sequence_h(node->right, 0);
	}
	return sr > sl ? sr : sl;
}

int longest_sequence(struct s_node *node)
{
	return longest_sequence_h(node, 0);
}

int mx(int a, int b, int c)
{
	return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int count2(struct s_node *node, int n)
{
	if (!node)
		return n;
	int ls = node->left ? node->left->value - node->value == 1 : 0;
	int rs = node->right ? node->right->value - node->value == 1 : 0;
	int left = count2(node->left, ls ? n + 1 : 1);
	int right = count2(node->right, rs ? n + 1 : 1);
	return mx(n, left, right);
}

int count(struct s_node *node, int n)
{
	int left, right;
	int ret = n;

	if (node->left)
	{
		if (node->left->value - node->value == 1)
			left = count(node->left, n + 1);
		else
			left = count(node->left, 1);
		if (left > ret)
			ret = left;
	}
	if (node->right)
	{
		if (node->right->value - node->value == 1)
			right = count(node->right, n + 1);
		else
			right = count(node->right, 1);
		if (right > ret)
			ret = right;
	}
	return ret;
}

int longest_sequence2(struct s_node *node)
{
	if (!node)
		return 0;
	return count(node, 1);
}

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
	// printf("%d\n", longest_sequence(&ten));
	printf("%d\n", longest_sequence2(&ten));
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
	// printf("%d\n", longest_sequence(&five));
	printf("%d\n", longest_sequence2(&five));
}

void three(void)
{
	struct s_node eighty = {80, NULL, NULL};
	struct s_node sixtyone = {61, NULL, NULL};
	struct s_node fortyone = {41, &eighty, NULL};
	struct s_node fifteen = {15, &sixtyone, NULL};
	struct s_node thirty = {30, &fifteen, &fortyone};
	// printf("%d\n", longest_sequence(&thirty));
	printf("%d\n", longest_sequence2(&thirty));
}

void four(void)
{
	struct s_node three = {3, 0, 0};
	struct s_node two = {2, 0, &three};
	struct s_node one = {1, 0, &two};
	struct s_node sixa = {6, 0, 0};
	struct s_node sixb = {6, &one, 0};
	struct s_node five = {1, &sixa, &sixb};
	// printf("%d\n", longest_sequence(&five));
	printf("%d\n", longest_sequence2(&five));
}

int main(void)
{
	one();
	two();
	three();
	four();
	// printf("%d\n", longest_sequence(NULL));
	printf("%d\n", longest_sequence2(NULL));
	struct s_node one = {1, NULL, NULL};
	// printf("%d\n", longest_sequence(&one));
	printf("%d\n", longest_sequence2(&one));
}
