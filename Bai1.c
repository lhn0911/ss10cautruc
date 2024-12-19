#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Khong du bo nho!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *initializeList()
{
    return NULL;
}

void addToHead(Node **head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void addToTail(Node **head, int data)
{
    Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node *temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteFromHead(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteFromTail(Node **head)
{
    if (*head == NULL)
    {
        printf("Danh sach rong!\n");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node *temp = *head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

Node *search(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void displayList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void freeList(Node **head)
{
    Node *temp;
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main()
{
    Node *head = initializeList();

    addToHead(&head, 10);
    addToHead(&head, 20);
    addToTail(&head, 30);
    addToTail(&head, 40);

    printf("Danh sach sau khi them phan tu: ");
    displayList(head);

    deleteFromHead(&head);
    printf("Danh sach sau khi xoa phan tu dau: ");
    displayList(head);

    deleteFromTail(&head);
    printf("Danh sach sau khi xoa phan tu cuoi: ");
    displayList(head);

    Node *found = search(head, 30);
    if (found)
    {
        printf("Tim thay phan tu: %d\n", found->data);
    }
    else
    {
        printf("Khong tim thay phan tu!\n");
    }

    freeList(&head);
    return 0;
}
