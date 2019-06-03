struct s_node {
	int value;
	struct s_node *next;
};

int	is_looping(struct s_node *node)
{
    struct s_node *slow, *fast;
    slow = fast = node;
    while (slow && fast && fast->next)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
            return 1;
    }
    return 0;
}

#include <stdio.h>
int main(void)
{
    struct s_node three = {3, NULL};
    struct s_node two = {2, &three};
    struct s_node one = {1, &two};

    printf("%d\n", is_looping(&one)); // no loop
    three.next = &two;
    printf("%d\n", is_looping(&one)); // loop
    three.next = NULL;
    one.next = &one;
    printf("%d\n", is_looping(&one)); // loop
    one.next = &two;
    printf("%d\n", is_looping(&one)); // no loop
    three.next = &three;
    printf("%d\n", is_looping(&one)); // loop
    // double loop
    three.next = NULL;
    printf("%d\n", is_looping(&one)); // no loop
    one.next = &three;
    three.next = &one;
    printf("%d\n", is_looping(&one)); // loop
}
