typedef struct s_list t_list;

struct s_list
{
	int		data;
	t_list	*next;
};

int	ascending(int a, int b)
{
	return (a <= b);
}

#include <stdbool.h>
static bool	validate_if_ordered(t_list *lst, int (*cmp)(int, int))
{
	while (lst->next)
	{
		if (cmp(lst->data, lst->next->data) == 0)
			return (false);
		lst = lst->next;
	}
	return (true);
}

t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*head;
	int		temp;

	if (!lst)
		return (0);
	head = lst;
	while (validate_if_ordered(lst, cmp) == false)
	{
		while (lst->next)
		{
			if (cmp(lst->data, lst->next->data) == 0)
			{
				temp = lst->data;
				lst->data = lst->next->data;
				lst->next->data = temp;
			}
			lst = lst->next;
		}
		lst = head;
	}
	return (head);
}

#include <stdlib.h>
#include <stdio.h>
int	main(void)
{
	t_list	*lst = NULL;

	t_list	*node1 = malloc(sizeof(t_list));
	if (!node1)
		return (0);
	t_list	*node2 = malloc(sizeof(t_list));
	if (!node2)
		return (free(node1), 0);
	t_list	*node3 = malloc(sizeof(t_list));
	if (!node3)
		return (free(node1), free(node2), 0);
	node1->data = 3;
	node1->next = node2;
	node2->data = 2;
	node2->next = node3;
	node3->data = 1;
	node3->next = NULL;
	lst = node1;
	printf("BEFORE:\n");
	printf("node 1: %i\n", lst->data);
	printf("node 2: %i\n", lst->next->data);
	printf("node 3: %i\n", lst->next->next->data);
	printf("node 4: %s\n", (char *) lst->next->next->next);
	sort_list(lst, &ascending);
	printf("AFTER:\n");
	printf("node 1: %i\n", lst->data);
	printf("node 2: %i\n", lst->next->data);
	printf("node 3: %i\n", lst->next->next->data);
	printf("node 4: %s\n", (char *) lst->next->next->next);
	return (0);
}