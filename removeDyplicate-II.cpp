#include <iostream>

using namespace std;

class Node
{

public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};

Node *CreateLinklist(int arr[], int index, int size)
{

    if (index >= size)
    {
        return NULL;
    }
    Node *temp;
    temp = new Node(arr[index]);
    temp->next = CreateLinklist(arr, index + 1, size);

    return temp;
}

Node *deleteDuplicates(Node *head)
{

    if (head == NULL)
    {
        return head;
    }
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL && curr->next != NULL)
    {
        // Check if the current node is a duplicate
        if (curr->next != NULL && curr->val == curr->next->val)
        {
            // Skip all duplicate nodes
            while (curr->next != NULL && curr->val == curr->next->val)
            {
                curr = curr->next;
            }
            // Now curr points to the last duplicate node, skip all duplicates
            if (prev == NULL)
            {
                // If there was no previous node, update head
                head = curr->next;
            }
            else
            {
                // Otherwise, link prev to the next distinct node
                prev->next = curr->next;
            }
        }
        else
        {
            // No duplicates, so move prev to curr
            prev = curr;
        }
        // Move curr to the next node
        curr = curr->next;
    }

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int arr[] = {1, 2, 2, 3, 4};
    Node *head;
    head = CreateLinklist(arr, 0, 5);

    head = deleteDuplicates(head);

    printList(head);
}