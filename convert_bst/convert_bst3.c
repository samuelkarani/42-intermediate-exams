struct s_node
{
	int value;
	struct s_node *right;
	struct s_node *left;
};

struct s_node *join(struct s_node *a, struct s_node *b)
{
	if (!b)
		return a;
	if (!a)
		return b;
	struct s_node *leftend = a->left;
	struct s_node *rightend = b->left;
	b->left = leftend;
	leftend->right = b;
	a->left = rightend;
	rightend->right = a;
	return a;
}

struct s_node *convert_bst(struct s_node *bst)
{
	if (!bst)
		return bst;
	struct s_node *left = convert_bst(bst->left);
	struct s_node *right = convert_bst(bst->right);
	bst->left = bst->right = bst;
	return join(join(left, bst), right);
}

#include <stdio.h>
void pr(struct s_node *lst)
{
	if (!lst)
		return;
	struct s_node *start = lst;
	do
	{
		printf("%d ", lst->value);
		lst = lst->right;
	} while (lst != start);
	printf("\n");
}

int main()
{
	struct s_node zero = (struct s_node){0, 0, 0};
	struct s_node four = (struct s_node){4, 0, 0};
	struct s_node three = (struct s_node){3, &four, 0};
	struct s_node one = (struct s_node){1, 0, &zero};
	struct s_node two = (struct s_node){2, &three, &one};
	pr(convert_bst(&two));
	pr(convert_bst(0));
}