#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack * s = malloc(sizeof(struct s_stack));
	s->top = NULL;
	return (s);
}

void *pop(struct s_stack *s)
{
	if (!s->top)
		return NULL;
	struct s_node *top = s->top;
	void *ret = top->content;
	s->top = top->next;
	free(top);
	return ret;
}

void push(struct s_stack *s, void *content)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	struct s_node *top = s->top;
	s->top = new;
	new->next = top;
}

void *peek(struct s_stack *stack)
{
	if (!stack->top)
		return NULL;
	return stack->top->content;
}

int isEmpty(struct s_stack *stack)
{
	return stack->top == NULL;
}

#include <stdio.h>
int                 main(void)
{
    struct s_stack  *stack = init();
    char            *content[] = {
      "one",
      "two",
      "three",
      "four",
      "five"
    };
    for (int i = 0; i < 5; i += 1)
    {
        push(stack, content[i]);
        printf("Content : %s\n", peek(stack));
        printf("Empty   : %s\n", (isEmpty(stack) ? "yes" : "no"));
    }
    for (int i = 5; i > 0; i -= 1)
    {
        pop(stack);
        printf("Content : %s\n", peek(stack));
        printf("Empty   : %s\n", (isEmpty(stack) ? "yes" : "no"));
    }
    return (0);
}
