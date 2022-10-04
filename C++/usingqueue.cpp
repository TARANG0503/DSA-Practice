#include<bits/stdc++.h>
#define ll long long
#define vi vector<int>
using namespace std;
class Stack{
    int N;
    queue<int> q1;
    queue<int> q2;
    public:
    Stack()
    {
        N=0;
    }
    void push(int x)
    {
        N++;
        q2.push(x);
        while(!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        queue<int> temp=q1;
        q1=q2;
        q2=temp;
    }
    void pop()
    {
        q1.pop();
        N--;
    }
    int top()
    {
        return q1.front();
    }
  int size()
  {return N;}
};
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
Stack st;
st.push(1);
st.push(2);
st.push(3);
cout<<st.top()<<endl;
st.pop();
cout<<st.top()<<endl;
return 0;
}