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

Node *sort0and1or2(Node *&head)
{
    if (head == NULL)
        return head;

    int count0 = 0, count1 = 1, count2 = 2;
    Node *temp = head;
    while (temp)
    {
        if (temp->data == 0)
        {
            count0++;
        }
        else if (temp->data == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (count0 > 0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1 > 1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    Node *head;
    int arr[] = {0, 1, 2, 0, 1, 1, 2};
    int index = 0;
    int size = sizeof(arr) / sizeof(arr[0]);
    head = Createlinklist(arr, index, size);
    head = sort0and1or2(head);

    Node *temp = head;

    cout << " list after sort : ";
    while (temp)
    {

        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}