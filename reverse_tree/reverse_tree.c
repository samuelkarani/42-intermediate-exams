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


#include <stdio.h>
void print(struct s_node *tree)
{
	if (!tree)
		return ;
	printf("%d ", tree->value);
	print(tree->left);
	print(tree->right);
}

int main(void)
{
	struct s_node g = {7, 0, 0};
	struct s_node f = {6, 0, 0};
	struct s_node e = {5, 0, 0};
	struct s_node d = {4, 0, 0};
	struct s_node c = {3, &g, &f};
	struct s_node b = {2, &e, &d};
	struct s_node a = {1, &c, &b};
	print(&a); printf("\n");
	reverse_tree(&a);
	print(&a);
}