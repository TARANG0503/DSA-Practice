/*Problem statement: Given an array of integers heights representing 
the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.

Input: array = {2,1,5,6,2,3} //heights of each bar
Output: 10
*/
#include<bits/stdc++.h>
using namespace std;

//Function to find largest rectangular area in histogram
long long getMaxArea(long long arr[], int n)
{
        //we maintain two arrays of size n
        //lb : for storing indexes of nearest smallest element on left
        //rb : for storing indexes of nearest smallest element on right
        vector<long long> lb, rb;
        
        //create an empty stack
        stack<long long>s;
        
        
        s.push(0);
        // push -1 to the stack for elements with no previous smaller element
        lb.push_back(-1); 
        
        //for lb[n]
        for(int i=1;i<n;++i)
        {
            //pop the indexes till we find the smaller bar value index
            while(!s.empty() && arr[i]<=arr[s.top()])
                s.pop();

            if(s.empty())
              lb.push_back(-1);
            else
              lb.push_back(s.top());
           
            s.push(i); 
        }
        
       
        while(!s.empty())
         s.pop();
         
        s.push(n-1);
        // push n to the stack for elements with no next smaller element
        rb.push_back(n);
        
        //for rb[n]
        for(int i=n-2;i>=0;--i)
        {
            //pop the indexes till we find the smaller bar value index
            while(!s.empty() && arr[i]<=arr[s.top()])
                s.pop();

            if(s.empty())
             rb.push_back(n);
            else
             rb.push_back(s.top());
            
            s.push(i); 
        }
         reverse(rb.begin(),rb.end());

        //Finding the max width of rectangle and corresponding maxArea for each bar
        //and finding max resultant area among them
        long long maxArea=0, width;
        for(int i=0;i<n;++i)
         {
             width=rb[i]-lb[i]-1;
             maxArea=max(maxArea , width*arr[i]);
         }
         
         return maxArea;
}


//Driver code
int main(){
    
    int n;
    cin>>n;

    long long arr[n];
    for(int i=0;i<n;++i)
      cin>>arr[i];
    cout<<getMaxArea(arr,n)<<endl;
    return 0;  
}