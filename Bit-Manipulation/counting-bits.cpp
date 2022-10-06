// DP

/*

The more simpler logic can be:
countBits(num) = countBits(all bits of num except the last bit) + countBits(the last bit)

101010101010
-----------
how many one's are there in this underlined pattern?

and

101010101010
           -
how many one's are there in this underlined pattern?
In other words, how many one's are there in i >> 1 and how many one's are there in i & 1 ?

The former is by definition res[i>>1] and the latter is by definition (i&1).

So combined these two, we get res[num] = res[num >> 1] + res & 1

*/
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);

        for (int i = 0; i <= num; ++i)
        {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};

// BITS Solution
class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);

        for (int i = 0; i <= num; ++i)
        {
            int num_bits = 0, n = i;
            while (n)
            {
                num_bits++;
                n &= (n - 1);
            }
            ans[i] = num_bits;
        }

        return ans;
    }
};