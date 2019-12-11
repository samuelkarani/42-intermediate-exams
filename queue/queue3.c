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
		return ;
	struct s_node *item = malloc(sizeof(struct s_node));
	item->content = content;
	item->next = NULL;
	if (!queue->first)
		queue->first = item;
	else
		queue->last->next = item;
	queue->last = item;
}

        void *dequeue(struct s_queue *queue)
{
	if (!queue || !queue->first)
		return NULL;
	struct s_node *item = queue->first;
	if (queue->first == queue->last)
		queue->first = queue->last = NULL;
	else
		queue->first = item->next;
	return item->content;
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
	printf("%d %s %s\n", isEmpty(queue), peek(queue), dequeue(queue));
	enqueue(queue, "a");
	printf("%d %s\n", isEmpty(queue), peek(queue));
	enqueue(queue, "b");
	printf("%d %s\n", isEmpty(queue), peek(queue));
	enqueue(queue, "c");
	printf("%d %s\n", isEmpty(queue), peek(queue));
	printf("%d %s %s\n", isEmpty(queue), dequeue(queue), peek(queue));
	printf("%d %s %s\n", isEmpty(queue), dequeue(queue), peek(queue));
	printf("%d %s %s\n", isEmpty(queue), dequeue(queue), peek(queue));
	printf("%d %s %s\n", isEmpty(queue), dequeue(queue), peek(queue));
}
*/
