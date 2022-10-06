class Solution
{
public:
    int findPosition(int n)
    {
        int count = 0, pos = 0, x = 0;
        while ((1 << x) <= n)
        {
            if ((1 << x) & n)
            {
                pos = x;
                count++;
            }
            x++;
        }

        if (count == 1)
        {
            return pos + 1;
        }
        return -1;
    }
};
