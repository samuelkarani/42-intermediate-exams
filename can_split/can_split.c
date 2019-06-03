struct s_node 
{
    int value;
    struct s_node *left;
    struct s_node *right;
};

int count(struct s_node *node)
{
	if (!node)
		return 0;
	int n = 1 + count(node->left) + count(node->right);
	node->value = n;
	return n;
}

int check_split(struct s_node *n, int s)
{
	if (!n)
		return 0;
	if (s - n->value == n->value)
		return 1;
	if (check_split(n->left, s))
		return 1;
	if (check_split(n->right, s))
		return 1;
	return 0;
}

int can_split(struct s_node *n)
{
	int cnt = count(n);
	if (!cnt || cnt % 2 != 0)
		return 0;
	return check_split(n, cnt);
}

#include <stdlib.h>
#include <stdio.h>
struct s_node* b(int v) {
    struct s_node* new = malloc(sizeof(struct s_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main() {
    struct s_node* ex1 = b(28);
    ex1->left = b(51);
    ex1->left->left = b(26);
    ex1->left->left->left = b(76);
    ex1->left->left->right = b(13);
    ex1->left->right = b(48);

    printf("%d\n", can_split(ex1));

   struct s_node* ex2 = b(30);
    ex2->left = b(15);
    ex2->left->left = b(61);
    ex2->right = b(41);
    ex2->right->right = b(80);

    printf("%d\n", can_split(ex2));

    struct s_node* ex3 = b(10);
    ex3->left = b(12);

    printf("%d\n", can_split(ex3));

    struct s_node* ex4 = b(5);
    ex4->left = b(1);
    ex4->right = b(6);
    ex4->right->left = b(7);
    ex4->right->left->left = b(3);
    ex4->right->left->left = b(2);
    ex4->right->right = b(4);
    ex4->right->right->right = b(8);

    printf("%d\n", can_split(ex4));
    return 0;
}
