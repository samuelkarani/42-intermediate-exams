#include <stdio.h>

   struct s_node {
                int           value;
                struct s_node *right;
                struct s_node *left;
        };

int leaf(struct s_node *node)
{
	return !node->left && !node->right;
}

        void pleft(struct s_node *root)
{
	if (!leaf(root))
		printf(" %d", root->value);
	if (root->left)
		pleft(root->left);
}

        void pright(struct s_node *root)
{
	if (root->right)
		pright(root->right);
	if (!leaf(root))
		printf(" %d", root->value);
}

void pleaves(struct s_node *root)
{
	if (leaf(root))
		printf(" %d", root->value);
	if (root->left)
		pleaves(root->left);
	if (root->right)
		pleaves(root->right);
}
        void perimeter(struct s_node *root)
{
	if (root)
	{
		printf("%d", root->value);
		if (root->left)
			pleft(root->left);
		if (!leaf(root))
			pleaves(root);
		if (root->right)
			pright(root->right);
	}
	printf("\n");
}
/*
#include <stdlib.h>
typedef struct s_node t_node;
t_node *cr(int value)
{
	t_node *node = malloc(sizeof(t_node));
	node->value = value;
	node->right = node->left = NULL;
	return node;
}
int main()
{
	t_node *node = cr(92);
	node->left = cr(85);
	node->left->left = cr(79);
	node->left->left->right = cr(10);
	node->left->left->right->left = cr(39);
	node->left->left->right->left->left = cr(35);
	node->left->left->right->left->left->left = cr(96);
	node->right = cr(26);
	node->right->right = cr(64);
	node->right->right->left = cr(40);
	node->right->right->right = cr(78);
	node->right->right->left->left = cr(88);
	node->right->right->left->right = cr(10);
	node->right->right->left->left->left = cr(12);
	node->right->right->left->left->right = cr(55);
	node->right->right->left->left->left->left = cr(58);
	node->right->right->left->left->right->left = cr(58);
	node->right->right->left->left->right->right= cr(41);
	node->right->right->left->right->left = cr(52);
	node->right->right->left->right->right = cr(87);
	node->right->right->left->right->right->right = cr(31);
	node->right->right->left->right->left->left = cr(22);
	node->right->right->left->right->left->right= cr(35);
	node->right->right->right->left = cr(2);
	node->right->right->right->left->left = cr(33);
	node->right->right->right->left->left->right = cr(55);
	node->right->right->right->left->right = cr(11);
	node->right->right->right->left->right->left = cr(99);
	node->right->right->right->right = cr(85);
	node->right->right->right->right->right = cr(51);
	perimeter(node);
	perimeter(NULL);
	perimeter(node->right->right->left->left);
	perimeter(node->right->right->left->left->right->right);
}
*/
