#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void fputchar(char c)
{
	write(1, &c, 1);
}

void fputstr(char *s)
{
	while (*s)
		fputchar(*s++);
}

void fputnbr(int n)
{
	if (n < 10)
		return fputchar(n + '0');
	fputnbr(n / 10);
	fputchar(n % 10 + '0');
}

int fstrlen(char *s)
{
	char *r = s;
	while (*s)
		s++;
	return (s - r) / sizeof(char);
}

int gatoi(char **s)
{
	int sum = 0;
	while (**s >= '0' && **s <= '9')
	{
		sum *= 10;
		sum += **s - '0';
		(*s)++;
	}
	return sum;
}

typedef struct s_node
{
	int name;
	int visited;
	int neighbors;
	struct s_node **connected;
} t_node;

typedef struct graph
{
	t_node **nodes;
	int capacity;
	int index;
} t_graph;

t_node *create(int v, int n)
{
	t_node *node = malloc(sizeof(t_node));
	node->name = v;
	node->visited = 0;
	node->connected = malloc(n * sizeof(t_node *));
	node->neighbors = 0;
	return node;
}

t_graph *initGraph(int n)
{
	t_graph *graph = malloc(sizeof(t_graph));
	graph->nodes = malloc(n * sizeof(t_node *));
	for (int i = 0; i < n; i++)
		graph->nodes[i]	= NULL;
	graph->index = 0;
	graph->capacity = n;
	return graph;
}

void printGraph(t_graph *graph)
{
	t_node *node;
	for (int i = 0; i < graph->index; i++)
	{
		node = graph->nodes[i];
		printf("%3d: ", node->name);
		for (int j = 0; j < node->neighbors; j++)
			printf("%d ", node->connected[j]->name);
		printf("\n");
	}
}

t_node *fetch(t_graph *graph, int v)
{
	t_node *node;
	int i;

	for (i = 0; i < graph->capacity; i++)
		if (graph->nodes[i] && graph->nodes[i]->name == v)
			break ;
	if (i == graph->capacity)
	{
		node = create(v, graph->capacity - 1);
		return graph->nodes[graph->index++] = node;
	}
	return graph->nodes[i];
}

void add(t_graph *graph, int v, int neighbor)
{
	t_node *node = fetch(graph, v);
	for (int i = 0; i < node->neighbors; i++)
		if (node->connected[i]->name == neighbor)
			return ;
	node->connected[node->neighbors++] = fetch(graph, neighbor);
}

void reset(t_graph *graph)
{
	for (int i = 0; i < graph->index; i++)
		graph->nodes[i]->visited = 0;
}

int dfs(t_node *node, int n)
{
	t_node *neighbor;
	node->visited = 1;
	// printf("node %d ", node->name);
	int ret, mx = n;
	for (int i = 0; i < node->neighbors; i++)
	{
		neighbor = node->connected[i];
		if (!neighbor->visited)
		{
			ret = dfs(neighbor, n + 1);
			if (ret > mx)
				mx = ret;
		}
	}
	node->visited = 0;
	return mx;
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		t_graph *graph;
		t_node *node;
		char *s;
		int l, a, b, n;

		l = fstrlen(s = av[1]);
		n = l / 4 + 1;
		graph = initGraph(n);
		while (1)
		{
			a = gatoi(&s);
			s++;
			b = gatoi(&s);
			add(graph, a, b);
			add(graph, b, a);
			if (!*s)
				break ;
			s++;
		}
		// printGraph(graph); printf("\n");
		int mx = 0, ret;
		for (int i = 0; i < graph->index; i++)
		{
			ret = dfs(graph->nodes[i], 1);
			if (ret > mx)
				mx = ret;
			reset(graph);
		}
		fputnbr(mx);
	}
	fputstr("\n");
}