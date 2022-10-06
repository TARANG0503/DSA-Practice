class Solution
{
    int countBits(int n)
    {
        int count = 0;
        while (n != 0)
        {
            count++;
            n = n & (n - 1);
        }
        return count;
    }

public:
    int countBitsFlip(int a, int b)
    {
        return countBits(a ^ b);
    }
};