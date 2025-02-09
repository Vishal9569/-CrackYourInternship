#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string longestCommonPrefix(vector<string> &str)
{

    sort(str.begin(), str.end());
    string s1 = str[0];
    string s2 = str[str.size() - 1];
    int j = 0, i = 0;

    string ans = "";
    while (i < s1.size() && j < s2.size())
    {
        if (s1[i] == s2[j])
        {
            ans += s1[i];
            i++, j++;
        }
        else
        {
            break;
        }
    }

    return ans;
}

int main()
{
    vector<string> str;
    str = {"sail", "saile", "saily"};

    cout << " logest common prefix : " << longestCommonPrefix(str);
}
