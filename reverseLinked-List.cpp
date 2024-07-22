#include <iostream>
#include <vector>
using namespace std;

class node
{

public:
    int value;
    node *next;

    node(int value)
    {
        this->value = value;
        next = NULL;
    }
};

node *CreateLinklist(int arr[], int index, int size)
{

    if (index >= size)
    {
        return NULL;
    }
    node *temp;
    temp = new node(arr[index]);
    temp->next = CreateLinklist(arr, index + 1, size);

    return temp;
}

node *reverseBetween(node *head, int left, int right)
{
    if (head == NULL)
        return NULL;

    node *dummy = new node(0);
    dummy->next = head;
    node *prev = dummy;

    for (int i = 1; i < left; i++)
    {
        prev = prev->next;
    }

    node *curr = prev->next;
    for (int i = 1; i <= right - left; i++)
    {
        node *temp = prev->next;
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = temp;
    }
    return dummy->next;
}

int main()
{
    node *head;
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;

    head = CreateLinklist(arr, 0, size);
    head = reverseBetween(head, 2, 4);

    while (head != NULL)
    {
        cout << head->value << " ";
        head = head->next;
    }
}