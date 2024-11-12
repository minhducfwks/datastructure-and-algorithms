#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next; // Use 'struct Node' for compatibility with C
    struct Node *prev;
} Node;

void PrintList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d\t", current->data);
        current = current->next;
    }
    printf("\n");
}

void InsertToPosition(Node **head, int data, int position)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory Error!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (position == 1)
    {
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            (*head)->prev = newNode;
            newNode->next = *head;
            *head = newNode;
        }
        return;
    }

    Node *current = *head;
    Node *prev = NULL;
    int currentPosition = 1;

    while (current != NULL && currentPosition < position)
    {
        prev = current;
        current = current->next;
        currentPosition++;
    }

    // If inserting at the end (or position is greater than list length)
    if (current == NULL && currentPosition == position)
    {
        prev->next = newNode;
        newNode->prev = prev;
        return;
    }
    else if (current == NULL)
    {
        printf("Position out of range!\n");
        free(newNode);
        return;
    }

    // Inserting in the middle
    prev->next = newNode;
    newNode->prev = prev;
    newNode->next = current;
    current->prev = newNode;
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
        (*head)->prev = NULL;
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
    curr->next->prev = prev;
    free(curr);
}

int main()
{
    Node *head = NULL;
    InsertToPosition(&head, 10, 1);
    InsertToPosition(&head, 20, 2);
    InsertToPosition(&head, 30, 3);
    InsertToPosition(&head, 15, 2); // Insert at position 2
    PrintList(head);
    DeleteAtPosition(&head,2);
    PrintList(head);    

    // Free the allocated memory (optional but recommended)
    while (head != NULL)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
