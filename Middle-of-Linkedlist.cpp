#include <iostream>
using namespace std;

class NodeList
{

public:
    int value;
    NodeList *next;

    NodeList(int data)
    {
        value = data;
        next = NULL;
    }
};

NodeList *Createlinkedlist(int arr[], int index, int size)
{
    NodeList *temp;
    if (index >= size)
    {
        return NULL;
    }
    temp = new NodeList(arr[index]);
    temp->next = Createlinkedlist(arr, index + 1, size);

    return temp;
}

NodeList *middleNode(NodeList *head)
{
    NodeList *fast = head;
    NodeList *slow = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{

    NodeList *head;
    NodeList *middle;
    int arr[] = {1, 2, 3, 4, 5};

    head = Createlinkedlist(arr, 0, 5);
    middle = middleNode(head);

    while (middle)
    {
        cout << middle->value << endl;
        middle = middle->next;
    }
}