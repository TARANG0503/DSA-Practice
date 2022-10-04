string binary(long long n)
{
    string r;
    
    while(n != 0)
    {
        r = (n % 2 == 0 ? '0' : '1') + r;
        n = n >> 1;
    }
    return r;
}
bool checkPal(string v , int start, int end)
{
    if(start > end)
    {
        return true;
    }
    
    if(v[start] != v[end])
    {
        return false;
    }
    else
    {
        return checkPal(v, start + 1, end - 1);
    }
}

bool checkPalindrome(long long N)
{
    string s = binary(N);
    
	int ans = checkPal(s, 0, s.size() - 1);
    
    return ans;
}