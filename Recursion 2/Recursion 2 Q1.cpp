class Solution {
public:
    int fib(int n) {
        
        if(n == 0 || n == 1)
        {
            return n;
        }
        
        int ans = fib(n - 1) + fib(n - 2);
        
        return ans;
    }
};