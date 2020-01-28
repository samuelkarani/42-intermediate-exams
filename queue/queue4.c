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
	queue->first = queue->last = NULL;
	return queue;
}

        void enqueue(struct s_queue *queue, void *content)
{
	if (!queue)
		return;
	struct s_node *node = malloc(sizeof(struct s_node));
	node->content = content;
	node->next = NULL;
	if (queue->last)
		queue->last->next = node;
	else
		queue->first = node;
	queue->last = node;
}

        void *dequeue(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return NULL;
	void *ret = queue->first->content;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	return ret;
}

        void *peek(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return NULL;
	return queue->first->content;
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
	printf("%d %s\n", isEmpty(queue), peek(queue));
	enqueue(queue, "a");
	printf("%d %s\n", isEmpty(queue), peek(queue));
	enqueue(queue, "b");
	printf("%d %s\n", isEmpty(queue), peek(queue));
	enqueue(queue, "c");
	printf("%d %s %s\n", isEmpty(queue), peek(queue), dequeue(queue));
	printf("%d %s %s\n", isEmpty(queue), peek(queue), dequeue(queue));
	printf("%d %s %s\n", isEmpty(queue), peek(queue), dequeue(queue));
	printf("%d %s %s\n", isEmpty(queue), peek(queue), dequeue(queue));
}
*/
