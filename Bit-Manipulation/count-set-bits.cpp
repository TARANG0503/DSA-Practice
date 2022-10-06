class Solution
{
public:
    int setBits(int N)
    {
        int count = 0;
        while (N != 0)
        {
            count++;
            N = N & (N - 1);
        }
        return count;
    }
};
