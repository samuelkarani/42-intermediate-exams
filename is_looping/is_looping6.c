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
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}
