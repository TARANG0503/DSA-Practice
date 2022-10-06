class Solution
{
public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        if (n == 0 || n == 1)
            return n;

        int count = 0, x = 0;
        while ((1 << x) <= n)
            x++;
        x--;

        count += (1 << (x - 1)) * x;
        count += n - (1 << x) + 1;
        return count + countSetBits(n - (1 << x));
    }
};