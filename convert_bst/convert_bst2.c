struct s_node {
                int           value;
                struct s_node *right;
                struct s_node *left;
        };

struct s_node *join(struct s_node *a, struct s_node *b)
{
	struct s_node *aback, *bback;
	if (!a)
		return b;
	if (!b)
		return a;
	
	aback = a->left;
	bback = b->left;

	aback->right = b;
   	b->left = aback;

	bback->right = a;
	a->left = bback;

	return a;
}

struct s_node *convert_bst(struct s_node *bst)
{
	struct s_node *right, *left;
	if (!bst)
		return 0;
	left = convert_bst(bst->left);
	right = convert_bst(bst->right);
	bst->right = bst;
	bst->left = bst;
	return join(join(left, bst), right);
}


#include <stdio.h>
void print_tree(struct s_node *node)
{
	if (node)
	{
	struct s_node *start = node;
	do
	{
		printf("%d ", node->value);
		node = node->right;
	} while (node != start);
	printf("\n");
	do
	{
		printf("%d ", node->value);
		node = node->left;
	} while (node != start);
	printf("\n");
	}
}

int main(void)
{
	struct s_node three = (struct s_node){3, 0, 0};
	struct s_node seven = (struct s_node){7, 0, 0};
	struct s_node five = (struct s_node){5, &seven, &three};
	// print_tree(convert_bst(&five));
	print_tree(convert_bst(&seven));
	print_tree(convert_bst(0));
}
