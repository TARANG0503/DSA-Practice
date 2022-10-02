 #include<bits/stdc++.h>
using namespace std;
 bool isOperator(char c)
{
    return (!isalpha(c) && !isdigit(c));
}
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
string infixToPrefix(string exp){
    stack<char> operators;
    stack<string> operands;
    for(int i=0;i<exp.length();i++)
    {
        if(exp[i]=='(')
        operators.push(exp[i]);

        else if(exp[i]==')')
        {
            while(!operators.empty()&&operators.top()!='(')
            {
                string op2=operands.top();
                operands.pop();
                string op1=operands.top();
                operands.pop();
                char op=operators.top();
                operators.pop();
                 string f=op+op1+op2;
                 operands.push(f);
                
            }
            operands.pop();//pop ( from stack
        }
         else if (!isOperator(exp[i])) {
            operands.push(string(1, exp[i]));
        }

        else
        {
            while(!operators.empty()&&prec(exp[i])<=prec(operators.top()))
            { 
             string op2=operands.top();
             operands.pop();
                string op1=operands.top();
                operands.pop();
                char op=operators.top();
                operators.pop();
                 string f=op+op1+op2;
                  operands.push(f);
            }
            operators.push(exp[i]);
        }
    }
 while(!operators.empty())
 {
     
             string op2=operands.top();
             operands.pop();
                string op1=operands.top();
                operands.pop();
                char op=operators.top();
                operators.pop();
                 string f=op+op1+op2;
                  operands.push(f);
 }

return operands.top();

}
int main() {
    string exp ="(A-B/C)*(A/K-L)"; /* "a+b*(c^d-e)^(f+g*h)-i"*/
    cout<<infixToPrefix(exp);
    return 0;
}