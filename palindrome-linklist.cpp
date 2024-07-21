#include <iostream>
#include <vector>
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

bool isPalindrome(Node *head)
{

    if (head == NULL)
        return false;

    vector<int> v;
    while (head != NULL)
    {
        v.push_back(head->val);
        head = head->next;
    }
    int start = 0;
    int end = v.size() - 1;
    while (start < end)
    {
        if (v[start] != v[end])
        {
            return false;
        }
        else
        {
            start++;
            end--;
        }
    }
    return true;
}
int main()
{
    Node *head;
    int arr[] = {2, 4, 5, 4, 2};
    head = CreateLinklist(arr, 0, 5);

    cout << isPalindrome(head);
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp; // Free the memory as we traverse
    }
}
