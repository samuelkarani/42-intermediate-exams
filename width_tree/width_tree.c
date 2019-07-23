struct s_node 
{
	int value;
	struct s_node *left;
	struct s_node *right;
};

int s;
int check(struct s_node *node, int n)
{
	if (!node)
		return n - 1;
	int a, b;
	a = b = 0;
	a = check(node->left, n + 1);
	b = check(node->right, n + 1);
	int sum = 1 + a + b - n * 2;
	if (sum > s)
		s = sum;
	return a > b ? a : b;
}

int	width_tree(struct s_node *n)
{
	if (!n)
		return 0;
	s = 0;
	check(n, 1);
	return s;
}

int height(struct s_node *n)
{
	if (!n)
		return 0;
	int a = 1 + height(n->left);
	int b = 1 + height(n->right);
	n->value = a > b ? a : b;
	return n->value;
}

int helper(struct s_node *n, int l)
{
	if (!n)
		return l;
	if (n->left && n->right
		&& n->left->value + 1 + n->right->value > l)
		l = n->left->value + 1 + n->right->value;
	if (n->left && n->left->value + 1 > l)
		l = n->left->value + 1;
	if (n->right && n->right->value + 1 > l)
		l = n->right->value + 1;
	int a = helper(n->left, l);
	int b = helper(n->right, l);
	return a > b ? a : b;
}

int	width_tree2(struct s_node *n)
{
	if (!n)
		return 0;
	height(n);
	return helper(n, 1);
}

int mx;

int helper2(struct s_node *n)
{
	if (!n)
		return 0;
	int a = 1 + helper2(n->left);
	int b = 1 + helper2(n->right);
	n->value = a > b ? a : b;
	if (n->left && n->right
		&& n->left->value + 1 + n->right->value > mx)
		mx = n->left->value + 1 + n->right->value;
	if (n->left && n->left->value + 1 > mx)
		mx = n->left->value + 1;
	if (n->right && n->right->value + 1 > mx)
		mx = n->right->value + 1;
	return n->value;
}

int width_tree3(struct s_node *n)
{
	if (!n)
		return 0;
	mx = 1;
	helper2(n);
	return mx;
}

typedef struct s_node t_n;
#include <stdio.h>
#include <stdlib.h>
struct s_node* b(int v) {
    struct s_node* new = malloc(sizeof(struct s_node));
    new->value = v;
    new->left = new->right = 0;
    return new;
}
int main ()
{
	t_n n1 = {
		.value = 1,
		.left = &(t_n){
			.value = 2,
			.left = &(t_n){
				.value = 3
			},
			.right = &(t_n){
				.value = 4,
				.left = &(t_n){
					.value = 6
				}
			}
		},
		.right = &(t_n){
			.value = 5,
			.left = &(t_n){
				.value = 7
			},
			.right = &(t_n){
				.value = 8
			}
		}
	};
	printf("The 1st width of the tree is: %d\n", width_tree3(&n1));
	printf("The 1st width of the tree is: %d\n", width_tree2(&n1));
	printf("The 1st width of the tree is: %d\n", width_tree(&n1));

	t_n n2 = {
		.value = 1,
		.left = &(t_n){
			.value = 2,
			.left = &(t_n){
				.value = 4,
				.left =&(t_n){
					.value = 5,
					.right = &(t_n){
						.value = 8
					}
				},
			.right = &(t_n){
				.value = 6
			}
		},
		.right = &(t_n){
			.value = 7,
			.left = &(t_n){
				.value = 9,
				.left = &(t_n){
					.value = 11
				},
				.right = &(t_n){
					.value = 12
				}
			},
			.right = &(t_n){
				.value = 10,
				.right = &(t_n){
					.value = 13
				}
			}
		}
	},
	.right = &(t_n){
		.value = 3
		}
	};
	printf("The 2nd width of the tree is: %d\n", width_tree3(&n2));
	printf("The 2nd width of the tree is: %d\n", width_tree2(&n2));
	printf("The 2nd width of the tree is: %d\n", width_tree(&n2));

	t_n n3 = {
		.value = 10,
		.right = &(t_n){
			.value = 12
		}
	};
	printf("The 3rd width of the tree is: %d\n", width_tree3(&n3));
	printf("The 3rd width of the tree is: %d\n", width_tree2(&n3));
	printf("The 3rd width of the tree is: %d\n", width_tree(&n3));

	t_n n4 = {
		.value = 25,
		.left = &(t_n){
			.value = 35,
			.left = &(t_n){
				.value = 12
			},
			.right = &(t_n){
				.value = 9,
				.left = &(t_n){
					.value = 3
				}
			}
		}
	};
	printf("The 4th width of the tree is: %d\n", width_tree3(&n4));
	printf("The 4th width of the tree is: %d\n", width_tree2(&n4));
	printf("The 4th width of the tree is: %d\n", width_tree(&n4));

	t_n n5 ={
		.value = 10
	};
	printf("The 5th width of the tree is: %d\n", width_tree3(&n5));
	printf("The 5th width of the tree is: %d\n", width_tree2(&n5));
	printf("The 5th width of the tree is: %d\n", width_tree(&n5));

	struct s_node* ex1 = b(28);
    ex1->left = b(51);
    ex1->left->left = b(26);
    ex1->left->left->left = b(76);
    ex1->left->left->right = b(13);
    ex1->left->right = b(48);
	printf("The 6th width of the tree is: %d\n", width_tree3(ex1));
	printf("The 6th width of the tree is: %d\n", width_tree2(ex1));
	printf("The 6th width of the tree is: %d\n", width_tree(ex1));

	return 0;
}