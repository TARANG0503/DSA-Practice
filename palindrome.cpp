class Solution {
public:
    bool isPalindrome(int n) 
    {
        if ((n<0) || (n%10==0 && n!=0))
            return false;
        int r=0;
        while (n>r){
            r=r*10+(n%10);
            n=n/10;
        }
        return n==r || n==r/10;
    }
};
