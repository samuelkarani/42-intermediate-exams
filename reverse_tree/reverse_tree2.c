struct s_node {
                int           value;
                struct s_node *right;
                struct s_node *left;
        };

        void reverse_tree(struct s_node *root)
{
	if (!root)
			return ;
	struct s_node *l = root->left;
	root->left = root->right;
	root->right = l;
	reverse_tree(root->left);
	reverse_tree(root->right);
}

/*
#include <stdlib.h>
struct s_node *create(int n)
{
	struct s_node *res = malloc(sizeof(struct s_node));
	res->value = n;
	res->left = res->right = 0;
	return res;
}

#include <stdio.h>
void print(struct s_node *root)
{
	if (!root)
		return ;
	printf("%d ", root->value);
	print(root->left);
	print(root->right);
}
int main()
{
	struct s_node *a = create(94);
	reverse_tree(a);
	print(a);
	printf("\n");

	a = 0;
	reverse_tree(a);
	print(a);
	printf("\n");

	a = create(1);
	a->left = create(2);
	a->right = create(3);
	a->left->left = create(4); 
	print(a);
	printf("\n");
	reverse_tree(a);
	print(a);
	printf("\n");

}
*/
