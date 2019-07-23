 struct s_node {
                int           value;
                struct s_node **nodes;
        };

        int height_tree(struct s_node *root)
{
	if (!root)
		return -1;
	int i, mx, h;
	i = mx = 0;
	while (root->nodes[i])
	{
		h = 1 + height_tree(root->nodes[i]);
		if (h > mx)
			mx = h;
		i++;
	}
	return mx;
}

/*
#include <stdlib.h>
#include <stdio.h>
struct s_node *create(int n)
{
	struct s_node *res = malloc(sizeof(struct s_node));
	res->value = n;
	struct s_node **nodes = malloc(sizeof(struct s_node *));
	nodes[0] = 0;
	res->nodes = nodes;
	return res;
}
int main()
{
	struct s_node b = {12, (struct s_node*[]){ 0 }};
	struct s_node a = {22, (struct s_node*[]){ &b, 0}};
	printf("%d\n", height_tree(&a));
	printf("%d\n", height_tree(&b));
	printf("%d\n", height_tree(0));
}
*/
