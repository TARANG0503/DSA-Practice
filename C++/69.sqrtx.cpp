// 69. Sqrt(x)
#include<iostream>
using namespace std;

int mySqrt(int x) {
        
    int start = 1;
    int end = x;
    int ans;
    int mid = start + (end - start)/2;
    
    if (x == 0)
        return 0;
    
    while(start <= end) {
        
        if(mid*mid == x)
            return mid;
        
        if(mid*mid < x){
            start = mid + 1;
            ans=mid;
        }
            
        else
            end = mid - 1;
    }
    return ans; 
}

int main(){
    // Input: x = 8
    // Output: 2
    cout<<mySqrt(8);
}