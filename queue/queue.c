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
	struct s_queue *s = malloc(sizeof(struct s_queue));
	s->first = NULL;
	s->last = NULL;
	return (s);
}

void enqueue(struct s_queue *queue, void *content)
{
	struct s_node *new = malloc(sizeof(struct s_node));
	new->content = content;
	new->next = NULL;
	if (!queue->last)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		queue->last->next = new;
		queue->last = new;
	}
}

void *dequeue(struct s_queue *queue)
{
	if (!queue->first)
		return (NULL);
	struct s_node *s = queue->first;
	void *ret = s->content;
	queue->first = s->next;
	if (s == queue->last)
		queue->last = s->next;
	free(s);
	return (ret);
}

void *peek(struct s_queue *queue)
{
	return (queue->first ? queue->first->content : NULL);
}

int isEmpty(struct s_queue *queue)
{
	return (!queue->first);
}

#include <stdio.h>
int main(void)
{
    struct s_queue  *queue = init();
    char            *content[] = {
      "one",
      "two",
      "three",
      "four",
      "five"
    };
    for (int i = 0; i < 5; i += 1)
    {
        enqueue(queue, content[i]);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
    for (int i = 5; i > 0; i -= 1)
    {
        dequeue(queue);
        printf("Content : %s\n", peek(queue));
        printf("Empty   : %s\n", (isEmpty(queue) ? "yes" : "no"));
    }
    return (0);
}
