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

int enqueue(list *lst, int value)
{
    if ((*lst) == NULL) {
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = NULL;
        *lst = tmp;
        return 1;
    }
    if ((*lst)->next == NULL) {
        list tmp = (list)malloc(sizeof(node));
        tmp->value = value;
        tmp->next = NULL;
        tmp->prev = *lst;
        (*lst)->next = tmp;
        return 1;
    }
}

list dequeue(list *lst)
{
    if (*lst == NULL) return NULL;
    list temp = *lst;
    (*lst) = (*lst)->next;
    (*lst)->prev = NULL;
    return temp;
}

int remove1(list *lst)
{
    if (*lst != NULL) {
        list del = *lst;
        if (((*lst)->prev != NULL) && ((*lst)->next != NULL)) {
            (*lst)->prev->next = (*lst)->next;
            (*lst)->next->prev = (*lst)->prev;
        }
        if (((*lst)->prev == NULL) && ((*lst)->next != NULL)) {
            (*lst)->next->prev = NULL;
            (*lst) = (*lst)->next;
        }
        if (((*lst)->prev != NULL) && ((*lst)->next == NULL)) {
            (*lst)->prev->next = NULL;
        }
        free(del);
    }
    return 1;
}

int isEmpty(list root)
{
    if (root) return 1;
    else return 0;
}

int destroy(list *root)
{
    list next;
    while (*root != NULL) {
        next = *root;
        *root = (*root)->next;
        free(next);
    }
    return 1;
}

int print(list *lst)
{
    list temp = *lst;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
    return 1;
}

int main() {
    list head, tail;
    int i, n, x;
    init(&head);

    scanf("%d", &n);
    if(n >= 1)
    {
        scanf("%d", &x);
        enqueue(&head, x);
        tail = head;
    }
    for (i = 1; i < n; i++) {
            scanf("%d", &x);
            enqueue(&tail, x);
            tail = tail->next;
        }
    print(&head);

    dequeue(&head);
    print(&head);
    //конец
    return 0;
}

        
