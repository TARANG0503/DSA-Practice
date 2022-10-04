void series(int n, int k, vector<int> &v)
{
    v.push_back(n);
    
    if(n <= 0)
    {
        return;
    }
    
    series(n - k, k, v);
    
    v.push_back(n);
}

vector<int> printSeries(int n, int k)
{
    vector<int> v;
    
    series(n, k, v);
    
    return v;
}