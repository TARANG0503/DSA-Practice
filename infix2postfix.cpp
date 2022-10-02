 
#include<bits/stdc++.h>
using namespace std;
 
//Function to return precedence of operators
int prec(char c) {
    if(c == '^')
        return 3;
    else if(c == '/')
        return 2;
    else if(c=='*')
         return 1;
    else if(c == '+' || c == '-')
        return -1;
    else
        return -2;
}
 
// The main function to convert infix expression
//to postfix expression
void infixToPostfix(string s) {
 
    stack<char> st; //For stack operations, we are using C++ built in stack
    string result;
 
    for(int i = 0; i < s.length(); i++) {
        char c = s[i];
 
        // If the scanned character is
        // an operand, add it to output string.
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
            result += c;
 
        // If the scanned character is an
        // ‘(‘, push it to the stack.
        else if(c == '(')
            st.push('(');
 
        // If the scanned character is an ‘)’,
        // pop and to output string from the stack
        // until an ‘(‘ is encountered.
        else if(c == ')') {
            while(st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
 
        //If an operator is scanned
        else {
            while(!st.empty() && prec(s[i]) <= prec(st.top())) {
                result += st.top();
                st.pop(); 
            }
            st.push(c);
        }
    }
 
    // Pop all the remaining elements from the stack
    while(!st.empty()) {
        result += st.top();
        st.pop();
    }
 
    cout << result << endl;
}
 
//Driver program to test above functions
int main() {
    string exp ="(a+b)*c+d/e"; /* "a+b*(c^d-e)^(f+g*h)-i"*/
    infixToPostfix(exp);
    return 0;
}
/*#include<iostream>
#include<stack> 
using namespace std;
struct Node{
    char data;
    Node *next;
}*top=NULL;
void push(char x)
{
    struct Node *t;
    t=new Node;
    if(t==NULL)
    cout<<"Stack is full";
    else 
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}
char pop()
{struct Node *t;
t=top;
char x=-1;
if(top==NULL)
cout<<"Stack is Empty";
else
{
    t=top;
    top=top->next;
    x=t->data;
    delete t;
}
return x;
}

int pre(char x)
{
    if(x=='+'||x=='-')
    return 1;
    else if(x=='*'||x=='/')
    return 2;
    return 0;
}
int isOperand(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/')
    return 0;
    else 
    return 1;
}
char *into_post(char *infix)
{ 
     int i=0,j=0;
    char *postfix;
    int len=strlen(infix);
    postfix=new char(len+1);
    while(infix!='\0')
    {
        if(isOperand(infix[i]))
        postfix[j++]=infix[i++];
        else
        {
            if(pre(infix[i])>pre(top->data))
            push(infix[i++]);
            else
            postfix[j++]=pop();
        }
    }
    while(top()!=NULL)
    postfix[j++]=pop();
   postfix[j]='\0';
   return postfix;
}

int main()
{
char *infix='a+b*c-d/e';
 char *postfix=into_post(infix);
 cout<<postfix;
    return 0;
}*/