#include <bits/stdc++.h>
using namespace std;
// iterative approach 
int maxWater(int arr[], int n)
{
    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        int left = arr[i];
        for (int j = 0; j < i; j++)
        {
            left = max(left, arr[j]);
        }
        int right = arr[i];
        for (int j = i + 1; j < n; j++)
        {
            right = max(right, arr[j]);
        }
        res += min(left, right) - arr[i];
    }
    return res;
}
// stack approach 
int rain_Water(vector<int> a)
{
    stack<int> st;
    int n = a.size(), ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.top()] < a[i])
        {
            int cur = st.top();
            st.pop();
            if (st.empty())
            {
                break;
            }
            int diff = i - st.top() - 1;
            ans += (min(a[st.top()], a[i]) - a[cur]) *diff;
        }
        st.push(i);
    }
    return ans;
}
int main()
{
    // int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    // int n = sizeof(arr) / sizeof(arr[0]);

    // cout << maxWater(arr, n);
    cout<<rain_Water(a);
    return 0;
}