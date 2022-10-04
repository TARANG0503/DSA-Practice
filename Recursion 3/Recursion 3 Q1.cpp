void reverseStr(string& str, int start, int end)
{
    if(start > end)
    {
        return;
    }
    
    swap(str[start], str[end]);
    start++;
    end--;
    
    reverseStr(str, start, end);
}

string reverseString(string str)
{
	reverseStr(str, 0, str.size() - 1);
    
    return str;
}