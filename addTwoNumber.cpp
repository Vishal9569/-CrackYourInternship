#include <iostream>

using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

Node *Createlinklist(int arr[], int index, int size)
{

    if (index >= size)
    {
        return NULL;
    }

    Node *temp;
    temp = new Node(arr[index]);
    temp->next = Createlinklist(arr, index + 1, size);

    return temp;
}

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node(-1);
    Node *temp = dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        sum += carry;
        carry = sum / 10;
        Node *node = new Node(sum % 10);
        temp->next = node;
        temp = temp->next;
    }

    return dummy->next;
}

int main()
{
    Node *head, *head1;
    int arr[] = {2, 4, 3};
    int arr1[] = {5, 6, 4};
    int index = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    head = Createlinklist(arr, index, size);
    head1 = Createlinklist(arr1, index, size);

    Node *result = addTwoNumbers(head, head1);

    Node *temp = result;

    cout << "List after adding the numbers: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    // Free the allocated memory
    while (result)
    {
        Node *temp = result;
        result = result->next;
        delete temp;
    }
    return 0;
}