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

typedef struct s_node t_n;
#include <stdio.h>
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
	printf("The 2nd width of the tree is: %d\n", width_tree(&n2));

	t_n n3 = {
		.value = 10,
		.right = &(t_n){
			.value = 12
		}
	};
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
	printf("The 4th width of the tree is: %d\n", width_tree(&n4));

	t_n n5 ={
		.value = 10
	};
	printf("The 5th width of the tree is: %d\n", width_tree(&n5));

	return 0;
}