#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{
	int value;
	struct node *next;
	struct node *prev;
} node;

typedef node* list;

int init(list *root)
{
	*root = NULL;
	return 1;
}

list find(list root, int value) 
{
	while (root != NULL) 
	{
		if (root->value == value)
			return root;
		root = root->next;
	}
	return root;
}

int removed(list *lst) 
{
	if (*lst != NULL) 
	{
		list del = *lst;
		if (((*lst)->prev != NULL) && ((*lst)->next != NULL)) 
		{
			(*lst)->prev->next = (*lst)->next;
			(*lst)->next->prev = (*lst)->prev;
		}
		if (((*lst)->prev == NULL) && ((*lst)->next != NULL))
		{
			(*lst) = (*lst)->next;
			(*lst)->prev = NULL;			
		}
		if (((*lst)->prev != NULL) && ((*lst)->next == NULL))
		{
			(*lst)->prev->next = NULL;
		}
		free(del);
	}
	return 1;
}

int isEmpty(list root) 
{
	if (root) return 0;
	else return 1;
}

int destroy(list *root)
{
	list next;
	while (*root != NULL)
	{
		next = *root;
		*root = (*root)->next;
		free(next);
	}
	return 1;
}

int append(list *lst, int value)
{
	if ((*lst) == NULL)
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->next = NULL;
		tmp->value = value;
		tmp->prev = NULL;
		*lst = tmp;
		return 1;
	}
	if ((*lst)->next == NULL) 
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->next = NULL;
		tmp->value = value;
		tmp->prev = *lst;
		(*lst)->next = tmp;
		return 1;
	}
	else 
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->next = (*lst)->next;
		tmp->value = value;
		tmp->prev = *lst;
		(*lst)->next->prev = tmp;
		(*lst)->next = tmp;
		return 1;
	}
}

int prepend(list *lst, int value)
{
	if ((*lst) == NULL)
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->next = NULL;
		tmp->value = value;
		tmp->prev = NULL;
		*lst = tmp;
		return 1;
	}
	if ((*lst)->prev == NULL) 
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->prev = NULL;
		tmp->value = value;
		tmp->next = *lst;
		(*lst)->prev = tmp;
		(*lst) = (*lst)->prev;
		return 1;
	}
	else 
	{
		list tmp = (list)malloc(sizeof(node));
		tmp->value = value;
		tmp->prev = (*lst)->prev;
		tmp->next = *lst;
		(*lst)->prev->next = tmp;
		(*lst)->prev = tmp;
		return 1;
	}
}

int print(list *lst) 
{
	list temp = *lst;
	while (temp != NULL) 
	{
		printf("%d ", temp->value);
		temp = temp->next;
	}
	printf("\n");
	return 1;
}

int main() 
{
	list head;
	init(&head);
	int i, x, n, k, m, a, b, c, d;
	//#1
	scanf("%d", &n);
	//#2
	scanf("%d", &x);
	append(&head, x);

	list temp = head;
	for (i = 1; i < n; i++) 
	{
		scanf("%d", &x);
		append(&temp, x);
		temp = temp->next;
	}
	print(&head);
	//#3
	scanf("%d", &k);
	if (k > n) printf("check data \n");
	else 
	{
		list del = head;
		for (i = 1; i < k; i++)
		{
				del = del->next;
		}
		removed(&del);
		if (k == 1) head = del;
	}
	print(&head);
	//#4	
	scanf("%d", &m);
	list delet = find(head, m);
	if (delet == head) removed(&head);
	else removed(&delet);
	print(&head);
	//#5
	scanf("%d%d", &a, &b);
	if (a > n) printf("check data \n");
	else
	{
		list next = head;
		for (i = 1; i < a; i++) 
		{
			next = next->next;
		}
		append(&next, b);
	}
	print(&head);
	//#6
	scanf("%d%d", &c, &d);
	if (c > n) printf("check data \n");
	if (c == 1) prepend(&head, d);
	else
	{
		list next = head;
		for (i = 1; i < c; i++) 
		{
			next = next->next;
		}
		prepend(&next, d);
	}
	print(&head);
	return 0;
}

