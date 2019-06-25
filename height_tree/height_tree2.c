struct s_node {
                int           value;
                struct s_node **nodes;
        };

int height_tree(struct s_node *root)
{
	if (!root)
		return -1;
	struct s_node **nodes = root->nodes;
	int count, max;
	max = 0;
	while (*nodes)
	{
		count = 1 + height_tree(*nodes);
		if (count > max)
			max = count;
		nodes++;
	}
	return max;
}

/**
#include <stdio.h>
int main(void)
{
	struct s_node c = (struct s_node){4, (struct s_node *[]){0}};
	struct s_node b = (struct s_node){3, (struct s_node *[]){&c}};
	struct s_node a = (struct s_node){2, (struct s_node *[]){0}};
	struct s_node root = (struct s_node){1, (struct s_node *[]){&a, &b, 0}};
	printf("%d\n", height_tree(&root));
	printf("%d\n", height_tree(&a));
	printf("%d\n", height_tree(&b));
	printf("%d\n", height_tree(&c));
	printf("%d\n", height_tree(NULL));
}
**/
