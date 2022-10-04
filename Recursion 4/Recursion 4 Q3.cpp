void solve(string str, string output, int index, vector<string>&ans)
{
    if(index >= str.size())
    {
        if(output.size() > 0)
        {
            ans.push_back(output);
        }
        return;
    }
    
    solve(str, output, index + 1, ans);
    
    output.push_back(str[index]);
    
    solve(str, output, index + 1, ans);
}

vector<string> subsequences(string str){
	
    vector<string> ans;
    string output;
    
    solve(str, output, 0, ans);
    
    return ans;
}
