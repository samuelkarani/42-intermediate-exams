struct s_node {
    int           value;
    struct s_node *right;
    struct s_node *left;
};

struct s_node *min(struct s_node *bst)
{
	while (bst && bst->left)
		bst = bst->left;
	return bst;
}

struct s_node *max(struct s_node *bst)
{
	while (bst && bst->right)
		bst = bst->right;
	return bst;
}

struct s_node *convert_bst_h(struct s_node *bst, int s)
{
    if (!bst)
        return 0;
    if (!bst->right && !bst->left)
        return bst;
    struct s_node *left, *right, *rleft, *rright;
    left = bst->left;
    right = bst->right;
    bst->left = rleft = convert_bst_h(left, 0);
    if (rleft)
        rleft->right = bst;
    bst->right = rright = convert_bst_h(right, 1);
    if (rright)
        rright->left = bst;
    if (s == -1)
        return bst;
    return !s ? max(bst) : min(bst);
}

struct s_node *convert_bst(struct s_node *bst)
{
    bst = convert_bst_h(bst, -1);
    struct s_node *p = bst;
    if (bst)
        while (bst->left)
            bst = bst->left;
    if (p)
        while (p->right)
            p = p->right;
    if (p)
        p->right = bst;
    if (bst)
        bst->left = p;
    return bst;
}

// version 2 - more efficient
struct s_node *join(struct s_node *left, struct s_node *right)
{
	if (!left)
		return right;
	if (!right)
		return left;
	struct s_node *leftLast, *rightLast;
	leftLast = left->left;
	rightLast = right->left;

	leftLast->right = right;
	right->left = leftLast;

	left->left = rightLast;
	rightLast->right = left;
	return left;
}

struct s_node *convert_bst2(struct s_node *bst)
{
	if (!bst)
		return 0;
	struct s_node *left = convert_bst2(bst->left);
	struct s_node *right = convert_bst2(bst->right);

	bst->right = bst->left = bst;

	return join(join(left, bst), right);
}

#include <stdio.h>
void print(struct s_node *lst)
{
    struct s_node *s = lst;
    if (lst)
    {
        do
        {
            printf("%d\n", lst->value);
            lst = lst->right;
        } while (lst != s);
    }
}

void one(void)
{
    struct s_node two = {2, NULL, NULL};
    struct s_node four = {4, NULL, NULL};
    struct s_node six = {6, NULL, NULL};
    struct s_node eight = {8, NULL, NULL};
    struct s_node three = {3, &four, &two};
    struct s_node seven = {7, &eight, &six};
    struct s_node five = {5, &seven, &three};
    print(convert_bst2(&five));
}

void    two(void)
{
    struct s_node seven = {7, NULL, NULL};
    print(convert_bst2(&seven));
}

void three(void)
{
    print(convert_bst2(NULL));
}

void four(void)
{
	struct s_node one = {1, NULL, NULL};
	struct s_node two = {2, NULL, &one};
	struct s_node three = {3, NULL, &two};
	print(convert_bst2(&three));
}

void five(void)
{
	struct s_node five = {5, NULL, NULL};
	struct s_node four = {4, &five, NULL};
	struct s_node three = {3, &four, NULL};
	print(convert_bst2(&three));
}

int main(void)
{
    one();
    printf("\n");
    two();
    printf("\n");
    three();
    printf("\n");
	four();
    printf("\n");
	five();
}
