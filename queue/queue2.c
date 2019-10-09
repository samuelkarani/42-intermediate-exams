#include <stdlib.h>

struct s_node {
                void *content;
                struct s_node *next;
        };
        struct s_queue {
                struct s_node *first;
                struct s_node *last;
        };

struct s_queue *init(void)
{
	struct s_queue *queue = malloc(sizeof(struct s_queue));
	queue->first = queue->last = 0;
	return queue;
}

        void enqueue(struct s_queue *queue, void *content)
{
	if (!queue)
		return ;
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content; node->next = NULL;
	struct s_node *oldLast = queue->last;
	queue->last = node;
	if (!queue->first)
		queue->first = node;
	else
		oldLast->next = node;
}

        void *dequeue(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return NULL;
	struct s_node *node = queue->first;
	if (node == queue->last)
		queue->first = queue->last = NULL;
	else
		queue->first = node->next;
	return node->content;
}

void *peek(struct s_queue *queue)
{
	if (queue && queue->first)
		return queue->first->content;
	return 0;
}

        int isEmpty(struct s_queue *queue)
{
	return !(queue && queue->first);
}

/*
#include <stdio.h>
int main()
{
	struct s_queue *queue = init();
	printf("%s %d\n", peek(queue), isEmpty(queue));
	enqueue(queue, "1"); printf("%s %d\n", peek(queue), isEmpty(queue));
	enqueue(queue, "2"); printf("%s %d\n", peek(queue), isEmpty(queue));
	enqueue(queue, "3"); printf("%s %d\n", peek(queue), isEmpty(queue));
	printf("%s %s %d\n", dequeue(queue), peek(queue), isEmpty(queue));
	printf("%s %s %d\n", dequeue(queue), peek(queue), isEmpty(queue));
	printf("%s %s %d\n", dequeue(queue), peek(queue), isEmpty(queue));
	printf("%s %s %d\n", dequeue(queue), peek(queue), isEmpty(queue));
}
*/
