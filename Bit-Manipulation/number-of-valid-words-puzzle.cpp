class Solution
{
public:
    vector<int> findNumOfValidWords(vector<string> &words, vector<string> &puzzles)
    {
        vector<int> ans;

        unordered_map<int, int> m;

        for (int i = 0; i < words.size(); ++i)
        {
            int bits = 0;
            for (int j = 0; j < words[i].size(); ++j)
            {
                bits |= 1 << (words[i][j] - 'a');
            }
            m[bits]++;
        }

        for (auto &p : puzzles)
        {
            int first = 1 << (p[0] - 'a'), res = 0;

            int mask = 0;
            for (auto &c : p)
            {
                mask |= 1 << (c - 'a');
            }

            int sub = mask;

            // generate all substrings of puzzle
            while (true)
            {
                if (sub & first)
                {
                    auto it = m.find(sub);
                    if (it != m.end())
                        res += it->second;
                }

                sub = (sub - 1) & mask;
                if (sub == 0)
                    break;
            }

            ans.push_back(res);
        }

        return ans;
    }
};