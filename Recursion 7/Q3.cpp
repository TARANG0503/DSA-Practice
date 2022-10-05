//first and last occurrence using resursion
void fOcc(vector<int>&arr, int start, int end, int k, int& firstOcc)
{
    if(start > end)
    {
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    if(arr[mid] == k)
    {
        firstOcc = mid;
        fOcc(arr, start, mid - 1, k, firstOcc);      
    }    
    else if(arr[mid] < k)
    {
        fOcc(arr, mid + 1, end, k, firstOcc);
    }
    else
    {
        fOcc(arr, start, mid - 1, k, firstOcc);
    }
}

//last occrance
void lOcc(vector<int>&arr, int start, int end, int k, int& lastOcc)
{
    if(start > end)
    {
        return;
    }
    
    int mid = start + (end - start) / 2;
    
    if(arr[mid] == k)
    {
        lastOcc = mid;
        lOcc(arr, mid + 1, end, k, lastOcc);      
    }    
    else if(arr[mid] < k)
    {
        lOcc(arr, mid + 1, end, k, lastOcc);
    }
    else
    {
        lOcc(arr, start, mid - 1, k, lastOcc);
    }
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> ans;
    
    int firstOcc = -1;
    int lastOcc = -1;
    
    fOcc(arr, 0, n - 1, k, firstOcc);
    lOcc(arr, 0, n - 1, k, lastOcc);
    
    ans.first = firstOcc;
    ans.second = lastOcc;
    
    return ans;
}