#include <stdlib.h>
struct s_node {
	int           data;
	struct s_node *next;
	struct s_node *other;
};

void free_all(struct s_node *node)
{
	struct s_node *next;
	while (node)
	{
		next = node->next;
		free(node);
		node = next;
	}
}

struct s_node *create(struct s_node *node)
{
	struct s_node *ret = malloc(sizeof(struct s_node));
	ret->data = node->data;
	ret->next = NULL;
	ret->other = NULL;
	return ret;
}

int find_idx(struct s_node *haystack, struct s_node *needle)
{
	if (!haystack || !needle)
		return -1;
	int idx = 0;
	while (haystack)
	{
		if (haystack == needle)
			return idx;
		haystack = haystack->next;
		idx++;
	}
	return -1;
}

struct s_node *find(struct s_node *node, int idx)
{
	while (node && idx-- > 0)
		node = node->next;
	return node;
}

struct s_node *clone_list(struct s_node *node)
{
	if (node)
	{
		struct s_node *ret, *p, *n;
		ret = p = create(node);
		n = node;
		node = node->next;
		while (node)
		{
			ret->next = create(node);
			node = node->next;
			ret = ret->next;
		}
		ret = p;
		node = n;
		int idx;
		while (ret)
		{
			idx = find_idx(n, node->other);
			if (idx >= 0)
				ret->other = find(p, idx);
			else
				ret->other = NULL;
			ret = ret->next;
			node = node->next;
		}
		return p;
	}
	else
		return NULL;
}

#include <stdio.h>
struct s_node *b(int v) {
    struct s_node *new = malloc(sizeof(struct s_node));
    new->data = v;
    new->next = 0;
    new->other = 0;
    return new;
}

void print(struct s_node *original, struct s_node *clone)
{
	puts("Original:");
    while (original)
	{
        printf("Val: %d | Other: %d\n", original->data, original->other ? original->other->data : -1);
        original = original->next;
    }
    puts("Clone:");
    while (clone)
	{
        printf("Val: %d | Other: %d\n", clone->data, clone->other ? clone->other->data : -1);
        clone = clone->next;
    }
}
int main() {
    struct s_node *a = b(1);
    a->next = b(2);
    a->next->next = b(3);
    a->next->next->next = b(4);
    a->next->next->next->next = b(5);
    a->next->next->next->next->next = b(6);
    a->next->next->next->next->next->next = b(7);

    struct s_node* a2 = a->next;
    struct s_node* a3 = a2->next;
    struct s_node* a4 = a3->next;
    struct s_node* a5 = a4->next;
    struct s_node* a6 = a5->next;
    struct s_node* a7 = a6->next;

    a2->other = a7;
    a3->other = a;
    a5->other = a5;
    a7->other = a4;

    struct s_node *clone = clone_list(a);
    print(a, clone);
	free_all(clone);
	clone = clone_list(NULL);
	print(NULL, clone);
	free_all(clone);
	a->next = NULL;
	clone = clone_list(a);
	print(a, clone);
	free_all(clone);
    return 0;
}
