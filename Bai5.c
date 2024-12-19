#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Khong the cap phat bo nho\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int value)
{
    if (root == NULL)
    {
        return createNode(value);
    }
    if (value < root->data)
    {
        root->left = insertNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void preOrder(Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(Node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

Node *search(Node *root, int value)
{
    if (root == NULL || root->data == value)
    {
        return root;
    }
    if (value < root->data)
    {
        return search(root->left, value);
    }
    return search(root->right, value);
}

void freeTree(Node *root)
{
    if (root != NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

void menu()
{
    printf("\nMenu:\n");
    printf("1. Them phan tu vao cay\n");
    printf("2. Duyet cay theo PreOrder (NLR)\n");
    printf("3. Duyet cay theo InOrder (LNR)\n");
    printf("4. Duyet cay theo PostOrder (LRN)\n");
    printf("5. Tim kiem phan tu trong cay\n");
    printf("6. Thoat\n");
    printf("Lua chon cua ban: ");
}

int main()
{
    Node *root = NULL;
    int choice, value;

    do
    {
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Nhap gia tri can them: ");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("Da them %d vao cay\n", value);
            break;
        case 2:
            printf("Duyet cay theo PreOrder: ");
            preOrder(root);
            printf("\n");
            break;
        case 3:
            printf("Duyet cay theo InOrder: ");
            inOrder(root);
            printf("\n");
            break;
        case 4:
            printf("Duyet cay theo PostOrder: ");
            postOrder(root);
            printf("\n");
            break;
        case 5:
            printf("Nhap gia tri can tim: ");
            scanf("%d", &value);
            Node *result = search(root, value);
            if (result != NULL)
            {
                printf("Tim thay %d trong cay\n", value);
            }
            else
            {
                printf("%d khong ton tai trong cay\n", value);
            }
            break;
        case 6:
            printf("Thoat chuong trinh\n");
            freeTree(root);
            break;
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
        }
    } while (choice != 6);

    return 0;
}
