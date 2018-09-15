#include <stdio.h>
#include <stdlib.h>

typedef struct list
{
    int value;
    int key;
    struct list *left;
    struct list *right;
} list;

typedef list* tree;

int init(tree *root)
{
    *root = NULL;
    return 1;
}

int newnode(int key, int vle, tree *root)
{
    tree tmp = (*root);
    tree buff = (tree)malloc(sizeof(list));
    buff->key = key;
    buff->value = vle;
    buff->left = NULL;
    buff->right = NULL;

    if ((*root) == NULL)
    {
        (*root) = buff;
        return 1;
    }

    while (1)
    {
        if (key > tmp->key)
        {
            if (tmp->right == NULL)
            {
                tmp->right = buff;
                return 1;
            }
 tmp = tmp->right;
        }
        else if (key < tmp->key)
        {
            if (tmp->left == NULL)
            {
                tmp->left = buff;
                return 1;
            }
            tmp = tmp->left;
        }
        else return 1;
    }
}

void preorderPrint(tree root)
{
    if (root == NULL) return;

    preorderPrint(root->left);
    printf("%d ", root->value);
    preorderPrint(root->right);
}

int main()
{
    tree head;
    init(&head);
    int i, vle, key, sz;

    scanf("%d", &sz);
    for (i = 0; i < sz; ++i)
    {
        scanf("%d", &key);
        scanf("%d", &vle);
        newnode(key, vle, &head);
    }

    preorderPrint(head);
    printf("\n");
    return 0;
}


