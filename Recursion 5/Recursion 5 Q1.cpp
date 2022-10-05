class Solution {
public:
    void solve(string digits, string output, int index, vector<string>&ans, string mapping[])
    {
        if(index >= digits.size())
        {
            ans.push_back(output);
            return;
        }
        
        int element = digits[index] - '0';
        
        string value = mapping[element];
        
        for(int i = 0; i < value.size(); i++)
        {
            output.push_back(value[i]);
            
            solve(digits, output, index + 1, ans, mapping);
            
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string output;
        
        if(digits.empty())
        {
            return ans;
        }
        
        string mapping[10] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        solve(digits, output, 0, ans, mapping);
        
        return ans;
    }
};