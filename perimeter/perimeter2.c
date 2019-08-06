#include <stdio.h>

struct s_node {
                int           value;
                struct s_node *right;
                struct s_node *left;
        };

void print_left(struct s_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
		return ;
	printf(" %d", root->value);
	print_left(root->left);
}

void print_right(struct s_node *root)
{
	if (!root)
		return ;
	if (!root->left && !root->right)
		return ;
	print_right(root->right);
	printf(" %d", root->value);
}

void print_leaves(struct s_node *root, int d)
{
	if (!root)
		return ;
	if (!root->left && !root->right && d > 0)
	{
		printf(" %d", root->value);
		return ;
	}
	print_leaves(root->left, d + 1);
	print_leaves(root->right, d + 1);
}
        void perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		print_left(root->left);
		print_leaves(root, 0);
		print_right(root->right);
	}
	printf("\n");
}

/*
#include <stdlib.h>
#include <stdio.h>
struct s_node *c(int v)
{
	struct s_node *s = malloc(sizeof(struct s_node));
	s->value = v;
	s->left = s->right = NULL;
	return s;
}

int main()
{
	perimeter(NULL);
	struct s_node *a = c(1);
	perimeter(a);
	a->left = c(2);
	a->right = c(3);
	perimeter(a);
	a->right->right = c(4);
	a->left->right = c(5);
	perimeter(a);

	struct s_node *b = c(92);
	b->left = c(85);
	b->left->left = c(79);
	b->left->left->right = c(10);
	b->left->left->right->left = c(39);
	b->left->left->right->left->left = c(35);
	b->left->left->right->left->left->left = c(96);
	b->right = c(26);
	b->right->right = c(64);
	b->right->right->left = c(40);
	b->right->right->left->left = c(88);
	b->right->right->left->left->left = c(12);
	b->right->right->left->left->left->left = c(58);
	b->right->right->left->left->right = c(55);
	b->right->right->left->left->right->left = c(58);
	b->right->right->left->left->right->right = c(41);
	b->right->right->left->right = c(10);
	b->right->right->left->right->left = c(52);
	b->right->right->left->right->left->left = c(22);
	b->right->right->left->right->left->right = c(35);
	b->right->right->left->right->right = c(87);
	b->right->right->left->right->right->right = c(31);
	b->right->right->right = c(78);
	b->right->right->right->left = c(2);
	b->right->right->right->left->left = c(33);
	b->right->right->right->left->left->right = c(55);
	b->right->right->right->left->right = c(11);
	b->right->right->right->left->right->left = c(99);
	b->right->right->right->right = c(85);
	b->right->right->right->right->right = c(51);
	perimeter(b);
}
*/
