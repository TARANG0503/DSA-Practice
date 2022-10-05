#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool operat(char c)
{
	if(c=='^'||c=='*'||c=='+'||c=='/'||c=='-')
	{
		return 1;
	}
	return 0;
}
int prec(char c)
{
	if(c=='^')
	{
		return 3;
	}
	if(c=='*'||c=='*')
	{
		return 2;
	}
	if(c=='+'||c=='-')
	{
		return 1;
	}
	return -1;
}
infixtoprefix(string s)
{
	stack <char> st;
	s="("+s+")";
	int l=s.length();
	for(int i=0;i<l;i++)
	{
		char c=s[i];
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			st.push(c);
		}
		else if(c=='(')
		{
			st.push(')');
		}
		else if(c==')')
		{
			st.push('(');
		}
		else if(operat(c))
		{
			st.push(c);
     	}
	}
	string e;
	string result;
	while(!st.empty())
	{
		e=e+st.top();
		st.pop();
	}
	for(int i=0;i<l;i++)
	{
		char c=e[i];
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			result=result+c;
		}
		else if(c=='(')
		{
			st.push('(');
		}
		else if(c==')')
		{
			while((!st.empty())&&(st.top()=='('))
			{
			  char temp=st.top();
			  st.pop();
			  result=result+temp;
			}
			st.pop();
		}
		else
		{
			while((!st.empty())&&(prec(st.top()))>=prec(c))
			{
				char temp=st.top();
				st.pop();
				result+=temp;
			}
			st.push(c);
		}
	}
	while(!st.empty())
	{
		char temp=st.top();
		st.pop();
		result+=temp;
	}
	cout<<result;
	for(int i=0;i<l;i++)
	{
		char c=result[i];
		if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
		{
			st.push(c);
		}
		else if(c=='(')
		{
			st.push(')');
		}
		else if(c==')')
		{
			st.push('(');
		}
		else if(operat(c))
		{
			st.push(c);
     	}
	}
}
int main()
{
	string s = ("x+y*z/w+u");
    cout << infixtoprefix(s);
    return 0;
}
