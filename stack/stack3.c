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
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	node->next = stack->top;
	stack->top = node;
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
	printf("%d %s\n", isEmpty(s), peek(s));
	push(s, "2");
	printf("%d %s\n", isEmpty(s), peek(s));
	push(s, "3");
	printf("%d %s\n", isEmpty(s), peek(s));
	
	printf("%s %d %s\n", pop(s), isEmpty(s), peek(s));
	printf("%s %d %s\n", pop(s), isEmpty(s), peek(s));
	printf("%s %d %s\n", pop(s), isEmpty(s), peek(s));
	printf("%s %d %s\n", pop(s), isEmpty(s), peek(s));
}
*/
