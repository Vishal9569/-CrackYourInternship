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

Node *removeElements(Node *head, int val)
{

    while (head != NULL && head->val == val)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    // If the list becomes empty after removing the head nodes
    if (head == NULL)
    {
        return NULL;
    }

    Node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->next->val == val)
        {
            Node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        }
        else
        {
            curr = curr->next;
        }
    }

    return head;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != nullptr)
    {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Node *head;
    int arr[] = {2, 4, 5, 5, 8};
    head = CreateLinklist(arr, 0, 5);
    head = removeElements(head, 5);

    printList(head);

    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp; // Free the memory as we traverse
    }
}
