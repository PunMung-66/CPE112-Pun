// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binaryTree
{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
} Node;

void insert_binaryTree(Node **root, int data)
{
    if (*root == NULL)
    {
        *root = (Node *)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    }
    else
    {
        if (data < (*root)->data)
        {
            insert_binaryTree(&(*root)->left, data);
        }
        else
        {
            insert_binaryTree(&(*root)->right, data);
        }
    }
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    char command[10];
    Node *root = NULL;
    int data;
    while (1)
    {
        scanf(" %s", command);
        if (strcmp(command, "INS") == 0)
        {
            scanf("%d", &data);
            insert_binaryTree(&root, data);
        }
        else if (strcmp(command, "INORDER") == 0)
        {
            inorder(root);
            printf("\n");
        }
        else if (strcmp(command, "PREORDER") == 0)
        {
            preorder(root);
            printf("\n");
        }
        else if (strcmp(command, "POSTORDER") == 0)
        {
            postorder(root);
            printf("\n");
        }
        else if (strcmp(command, "END") == 0)
        {
            inorder(root);
            break;
        }
    }
    return 0;

}