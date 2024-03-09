// Punnawat Mungkalarungsi 66070503436
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct AVL
{
    int data;
    struct AVL *left;
    struct AVL *right;
    int height;
} Node;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int data)
{
    if (node == NULL)
        return (newNode(data));

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    else
        return node;

    node->height = 1 + max(height(node->left), height(node->right));

    int balance = getBalance(node);

    if (balance > 1 && data < node->left->data)
        return rightRotate(node);

    if (balance < -1 && data > node->right->data)
        return leftRotate(node);

    if (balance > 1 && data > node->left->data)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && data < node->right->data)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
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

void get_insert(Node *root, int value)
{
    int i = 0, arr[1000];
    char temp;
    do
    {
        scanf("%d%c", &arr[i], &temp);
        i++;
    } while (temp != '\n');
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else
    {
        if ((root->left == NULL) || (root->right == NULL))
        {
            Node *temp = root->left ? root->left : root->right;

            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
                *root = *temp;
            free(temp);
        }
        else
        {
            Node *temp = root->right;
            while (temp->left != NULL)
                temp = temp->left;

            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }

    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int find(Node *root, int value)
{
    if (root == NULL)
        return 0;
    if (root->data == value)
        return 1;
    if (root->data > value)
        return find(root->left, value);
    return find(root->right, value);
}

int main()
{
    char opt[6];
    Node *root = NULL;
    int value;

    while (1)
    {
        scanf(" %s", &opt);
        if (strcmp(opt, "INSERT") == 0)
        {
            int i = 0, size, arr[100];
            i = 0;
            char temp;
            do
            {
                if (scanf("%d%c", &arr[i], &temp) == EOF)
                    break;
                i++;
            } while (temp != '\n');
            size = i;
            for (i = 0; i < size; i++)
                root = insert(root, arr[i]);
        }
        else if (strcmp(opt, "DELETE") == 0)
        {
            int i = 0, size, arr[100];
            i = 0;
            char temp;
            do
            {
                if (scanf("%d%c", &arr[i], &temp) == EOF)
                    break;
                i++;
            } while (temp != '\n');
            size = i;
            for (i = 0; i < size; i++)
            {
                if (find(root, arr[i]) == 0)
                    printf("Node not found.\n");
                else
                    root = deleteNode(root, arr[i]);
            }
        }
        else if (strcmp(opt, "PRINT") == 0)
        {
            if (root == NULL)
                printf("Tree is empty.");
            else
                preorder(root);
            printf("\n");
        }
        else if (strcmp(opt, "EXIT") == 0)
            break;
        else
            printf("Invalid command.\n");
    }
    return 0;
}
