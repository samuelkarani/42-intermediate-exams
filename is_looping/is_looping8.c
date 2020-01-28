struct s_node {
        int value;
        struct s_node *next;
};

int     is_looping(struct s_node *node)
{
	struct s_node *fast, *slow;
	fast = slow = node;
	while (slow && fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			return 1;
	}
	return 0;
}

/*
#include <stdio.h>
typedef struct s_node t_node;
int main()
{
	t_node three = (t_node){3, 0};
	printf("%d\n", is_looping(&three));
	t_node two = (t_node){2, &three};
	t_node one = (t_node){1, &two};
	printf("%d\n", is_looping(&one));
	three.next = &one;
	printf("%d\n", is_looping(&one));
	printf("%d\n", is_looping(0));
}
*/
