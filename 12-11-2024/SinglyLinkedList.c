#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int Data;
    struct Node *next;  // Note: struct Node instead of Node for compatibility with C
} Node;

int GetListLength(Node *head)
{
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void PrintList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\t", current->Data);
        current = current->next;
    }
    printf("\n");  // To end the line after printing all elements
}

void InsertToPosition(Node **head, int data, int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (!newNode)
    {
        printf("Memory Error\n");
        return;
    }
    newNode->Data = data;
    newNode->next = NULL;  // Initialize next to NULL

    if (position == 1)
    {
        newNode->next = *head;
        *head = newNode;
    }
    else
    {
        Node *prev = NULL;
        Node *curr = *head;
        int currentPosition = 1;
        
        while (curr != NULL && currentPosition < position)
        {
            prev = curr;
            curr = curr->next;
            currentPosition++;
        }
        
        if (prev != NULL)
        {
            prev->next = newNode;
        }
        newNode->next = curr;
    }
}

void DeleteAtPosition(Node **head, int position)
{
    if (*head == NULL)
    {
        printf("List Empty\n");
        return;
    }
    Node *curr = *head;
    if (position == 1)
    {
        *head = (*head)->next;
        free(curr);
        return;
    }

    Node *prev = curr;
    int currentPosition = 1;
    
    while (curr != NULL && currentPosition < position)
    {
        prev = curr;
        curr = curr->next;
        currentPosition++;
    }
    if (curr == NULL)
    {
        printf("Position does not exist.\n");
        return;
    }
    prev->next = curr->next;
    free(curr);
}

void DeleteLinkedList(Node **head)
{
    Node *curr = *head;
    Node *tmp;
    while (curr)
    {
        tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    *head = NULL;
}

int main(int argc, char const *argv[])
{
    Node *head = NULL;  // Initialize head to NULL
    InsertToPosition(&head, 3, 1);
    InsertToPosition(&head, 4, 1);
    InsertToPosition(&head, 5, 1);
    InsertToPosition(&head, 1, 1);
    PrintList(head);

    DeleteLinkedList(&head);  // Free memory after use
    return 0;
}
