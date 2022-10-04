#include <bits/stdc++.h>
using namespace std;

bool check(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' || i == '[' || i == '{')
            st.push(i);
        else
        {
            if (st.empty() || (st.top() == '(' && i != ')') || (st.top() == '[' && i != ']') || (st.top() == '{' && i != '}'))
                return 0;
            st.pop();
        }
    }
    if (st.empty())
        return 1;
    else
        return 0;
}