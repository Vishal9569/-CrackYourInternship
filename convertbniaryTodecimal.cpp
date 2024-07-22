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

int getDecimalValue(NodeList *head)
{
    if (head == NULL && head->next == NULL)
        return 0;

    int decimalValue = 0;
    while (head != nullptr)
    {
        decimalValue = (decimalValue << 1) | head->value;
        head = head->next;
    }
    return decimalValue;
}

int main()
{

    NodeList *head;
    NodeList *middle;
    int arr[] = {1, 0, 1, 0};

    head = Createlinkedlist(arr, 0, 4);
    cout << getDecimalValue(head);
}
