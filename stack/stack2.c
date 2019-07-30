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
	struct s_stack *res = malloc(sizeof(struct s_stack));
	res->top = NULL;
	return res;
}

        void *pop(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return NULL;
	void *res = stack->top->content;
	stack->top = stack->top->next;
	return res;
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
	return stack && stack->top ? stack->top->content : NULL;
}

        int isEmpty(struct s_stack *stack)
{
	return !(stack && stack->top);
}
/*
#include <stdio.h>
int main(void)
{
	struct s_stack *stack = init();
	printf("pop %s peek %s isEmpty %d\n", pop(stack), peek(stack), isEmpty(stack));
	push(stack, "a");
	printf("added %s peek %s isEmpty %d\n", "a", peek(stack), isEmpty(stack));
	push(stack, "b");
	printf("added %s peek %s isEmpty %d\n", "b", peek(stack), isEmpty(stack));
	push(stack, "c");
	printf("added %s peek %s isEmpty %d\n", "c", peek(stack), isEmpty(stack));

	printf("popped %s peek %s isEmpty %d\n", pop(stack), peek(stack), isEmpty(stack));
	printf("popped %s peek %s isEmpty %d\n", pop(stack), peek(stack), isEmpty(stack));
	printf("popped %s peek %s isEmpty %d\n", pop(stack), peek(stack), isEmpty(stack));
	printf("popped %s peek %s isEmpty %d\n", pop(stack), peek(stack), isEmpty(stack));
}
*/
