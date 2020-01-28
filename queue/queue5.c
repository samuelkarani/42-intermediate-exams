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
	if (queue)
	{
		struct s_node *node = malloc(sizeof(struct s_node));
		node->content = content; node->next = NULL;
		if (queue->last)
			queue->last->next = node;
		else
			queue->first = node;
		queue->last = node;
	}
}

   void *dequeue(struct s_queue *queue)
{
	if (queue && queue->first)
	{
		void *content = queue->first->content;
		if (queue->first == queue->last)
			queue->last = NULL;
		queue->first = queue->first->next;	
		return content;
	}
	return NULL;
}

        void *peek(struct s_queue *queue)
{
	if (queue && queue->first)
		return queue->first->content;
	return NULL;
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
	enqueue(queue, "1");
	printf("%s %d\n", peek(queue), isEmpty(queue));
	enqueue(queue, "2");
	printf("%s %d\n", peek(queue), isEmpty(queue));
	enqueue(queue, "3");
	printf("%s %d\n", peek(queue), isEmpty(queue));
	printf("%s %d %s\n", peek(queue), isEmpty(queue), dequeue(queue));
	printf("%s %d %s\n", peek(queue), isEmpty(queue), dequeue(queue));
	printf("%s %d %s\n", peek(queue), isEmpty(queue), dequeue(queue));
	printf("%s %d %s\n", peek(queue), isEmpty(queue), dequeue(queue));
}
*/
