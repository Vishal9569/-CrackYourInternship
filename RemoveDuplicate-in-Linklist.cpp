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

    Node *curr = head;

    if (head == NULL)
    {
        return NULL;
    }

    while (curr != NULL && curr->next != NULL)
    {

        if (curr->val == curr->next->val)
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
    int arr[] = {2, 4, 5, 2};
    Node *head;
    head = CreateLinklist(arr, 0, 3);

    head = deleteDuplicates(head);

    printList(head);
}