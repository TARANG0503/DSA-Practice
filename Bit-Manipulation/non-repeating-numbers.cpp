class Solution
{
public:
    vector<int> singleNumber(vector<int> nums)
    {
        vector<int> ans(2);

        int res = 0;
        for (int i : nums)
            res = res ^ i;

        // get the bit where the 2 numbers differ
        int bit_num = -1, i = 0;
        while (bit_num == -1)
        {
            if (res & 1 << i)
            {
                bit_num = i;
            }
            i++;
        }

        int res1, res2;
        res1 = res2 = res;
        for (int i : nums)
            if (i & 1 << bit_num)
                res1 = res1 ^ i;
            else
                res2 = res2 ^ i;

        ans[0] = (res1 < res2) ? res1 : res2;
        ans[1] = (res1 == ans[0]) ? res2 : res1;

        return ans;
    }
};