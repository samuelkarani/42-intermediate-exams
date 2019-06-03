struct s_node {
	void *content;
	struct s_node *next;
};

void *intersection(struct s_node *lst1, struct s_node *lst2)
{
	struct s_node *l2 = lst2;
	while (lst1)
	{
		lst2 = l2;
		while (lst2)
		{
			if (lst2 == lst1)
				return lst1;
			lst2 = lst2->next;
		}
		lst1 = lst1->next;
	}
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
struct s_node* b(void* v) {
	struct s_node* new = malloc(sizeof(struct s_node));
	new->content = v;
	new->next = 0;
	return new;
}

int main() {
	struct s_node* a = b("a");
	a->next = b("b");
	a->next->next = b("c");
	a->next->next->next = b("d");
	a->next->next->next->next = b("e");
	a->next->next->next->next->next = b("f");

	struct s_node* c = b("g");
	c->next = b("h");
	c->next->next = b("i");
	c->next->next->next = b("j");
	c->next->next->next->next = b("k");
	c->next->next->next->next->next = b("l");

	struct s_node* ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);

	c->next->next = a->next->next->next;
	ret = intersection(a, c);
	printf("%s\n", ret ? ret->content : 0);
	return 0;
}
