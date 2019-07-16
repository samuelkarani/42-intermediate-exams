struct s_node {
                int           value;
                struct s_node **nodes;
        };


int height_tree(struct s_node *root)
{
	if (!root)
		return -1;
	int n, c, i;
	i = n = 0;
	while (root->nodes[i])
	{
		c = 1 + height_tree(root->nodes[i++]);
		if (c > n)
			n = c;
	}
	return n;
}

/*
#include <stdio.h>
int main(void)
{
	struct s_node g = {13, (struct s_node *[]){0}};
	struct s_node f = {1, (struct s_node *[]){0}};
	struct s_node e = {99, (struct s_node *[]){0}};
	struct s_node d = {11, (struct s_node *[]){&g, 0}};
	struct s_node c = {34, (struct s_node *[]){&f, &e, 0}};
	struct s_node b = {52, (struct s_node *[]){&d, 0}};
	struct s_node a = {94, (struct s_node *[]){&b, &c, 0}};
	printf("%d\n", height_tree(&a));
	printf("%d\n", height_tree(&b));
	printf("%d\n", height_tree(&c));
	printf("%d\n", height_tree(&d));
	printf("%d\n", height_tree(&g));
	printf("%d\n", height_tree(0));
}
*/
