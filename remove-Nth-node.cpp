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

Node *removeNthFromEnd(Node *head, int n)
{

    int count = 0;
    Node *temp = head;

    while (temp)
    {
        count++;
        temp = temp->next;
    }
    count -= n;

    if (count == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *prev = NULL;
    Node *curr = head;

    while (count--)
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    delete curr;

    return head;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    Node *head;
    head = CreateLinklist(arr, 0, 5);

    head = removeNthFromEnd(head, 2);

    printList(head);

    return 0;
}