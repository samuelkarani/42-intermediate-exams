struct s_node {
		int           value;
		struct s_node **nodes;
	};

int height_tree(struct s_node *root)
{
	if (!root)
		return -1;
	if (!(root->nodes)[0])
		return 0;
	int l = -1;
	int i = 0;
	struct s_node **nodes = root->nodes;
	while (nodes[i])
	{
		int h = 1 + height_tree(nodes[i]);
		if (h > l)
			l = h;
		i++;
	}
	return l;
}
