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
	struct s_stack *stack = malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return stack;
}

        void *pop(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return NULL;
	void *ret = stack->top->content;
	stack->top = stack->top->next;
	return ret;
}

        void push(struct s_stack *stack, void *content)
{
	if (!stack)
		return ;
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = stack->top;
	stack->top = new;
}

        void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return NULL;
	return stack->top->content;
}

        int isEmpty(struct s_stack *stack)
{
	return !(stack && stack->top);
}

/*
#include <stdio.h>
int main()
{
	struct s_stack *s = init();
	printf("%s %d %s\n", pop(s), isEmpty(s), peek(s));
	push(s, "1");
	printf("%s %d\n", peek(s), isEmpty(s));
	push(s, "2");
	printf("%s %d\n", peek(s), isEmpty(s));
	push(s, "3");
	printf("%s %d\n", peek(s), isEmpty(s));

	printf("%s %d %s\n", peek(s), isEmpty(s), pop(s));
	printf("%s %d %s\n", peek(s), isEmpty(s), pop(s));
	printf("%s %d %s\n", peek(s), isEmpty(s), pop(s));
	printf("%s %d %s\n", peek(s), isEmpty(s), pop(s));
}
*/
