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

node *createLinklist(vector<int> &ans, int index)
{
    // base condition //
    if (index >= 5)
    {
        return NULL;
    }

    node *temp;
    temp = new node(ans[index]);
    temp->next = createLinklist(ans, index + 1);

    return temp;
}

vector<int> reverselinklist(int arr[], int size)
{
    vector<int> ans;
    for (int i = size - 1; i >= 0; i--)
    {
        ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{
    node *head;
    int arr[] = {2, 4, 6, 8, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    ans = reverselinklist(arr, size);
    head = createLinklist(ans, 0);
 
    while (head)
    {
        cout << head->value << " ";
        head = head->next;
    }
}
