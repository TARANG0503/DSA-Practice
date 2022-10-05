#include <iostream>
#include <vector>
using namespace std;

void countPermute(string str, int index, vector<string> &ans)
{
    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }

    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);

        countPermute(str, index + 1, ans);

        //swap(str[index], str[i]);
    }
}

int main()
{
    string str;
    cin >> str;

    vector<string> ans;

    countPermute(str, 0, ans);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}