/*
TARANG0503 has been working with an organization called 'Money Traders' for the past few years. The organization is into the money trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], then the stock spans will be [1, 1, 1, 2, 1, 4, 6].

*/
#include <iostream>
using namespace std;
#include<stack>
int* stockSpan(int *price, int size)  {
   int *a=new int[size];
    int i=0;
    stack<int>s;
    s.push(0);
    a[0]=1;
    for(i=1;i<size;i++) 
    {
     while (!s.empty() && price[s.top()] <price[i]) {
            s.pop(); 
     }
        a[i] = (s.empty()) ? (i + 1) : (i - s.top()); 
  
        s.push(i); 
    }
        return a;
    
}  
int main() {
    int size;
    cin >> size;

    int *input = new int[size];
    for (int i = 0; i < size; i++) {
        cin >> input[i];
    }

    int *output = stockSpan(input, size);
    for (int i = 0; i < size; i++) {
        cout << output[i] << " ";
    }

    cout << "\n";

    delete[] input;
    delete[] output;
}
