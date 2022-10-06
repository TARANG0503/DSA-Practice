class Solution
{
public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n)
    {
        if (!n)
            return false;
        return (n & (n - 1)) ? false : true;
    }
};