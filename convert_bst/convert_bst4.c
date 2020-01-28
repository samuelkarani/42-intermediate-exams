    struct s_node {
                int           value;
                struct s_node *right;
                struct s_node *left;
        };

struct s_node *join(struct s_node *a, struct s_node *b)
{
	if (!a)
		return b;
	if (!b)
		return a;

	struct s_node *blast = b->left;

	a->left->right = b;
	b->left = a->left;

	a->left = blast;
	blast->right = a;

	return a;
}

  struct s_node *convert_bst(struct s_node *bst)
{
	if (!bst)
		return 0;
	struct s_node *left = convert_bst(bst->left);
	struct s_node *right = convert_bst(bst->right);
	bst->left = bst;
	bst->right = bst;
	return join(join(left, bst), right);
}

/*
#include <stdio.h>
#include <stdlib.h>
typedef struct s_node t_node;

t_node *cr(int n)
{
	t_node *node = malloc(sizeof(t_node));
	node->value = n;
	node->right = node->left = NULL;
	return node;
}

t_node *get_node()
{
	t_node *node = cr(5);
	node->left = cr(3);
	node->left->left = cr(2);
	node->left->left->left = cr(1);
	node->left->right = cr(4);
	node->right = cr(7);
	node->right->left = cr(6);
	node->right->right = cr(8);
	return node;
}

void print(t_node *node)
{
	if (!node)
		return;
	t_node *start = node;
	do {
		printf("%d ", node->value);
		node = node->right;
	} while (node != start);
	printf("\n");
}

int main()
{
	t_node *node = get_node();
	print(convert_bst(node));
	node = get_node();
	print(convert_bst(node->left));
	node = get_node();
	print(convert_bst(node->left->left));
	node = get_node();
	print(convert_bst(node->left->left->left));
	node = get_node();
	print(convert_bst(node->right));
	node = get_node();
	print(convert_bst(node->right->right));
	node = get_node();
	print(convert_bst(NULL));
}
*/
