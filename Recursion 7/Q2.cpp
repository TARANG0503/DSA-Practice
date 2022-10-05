//first and last occurrence
int fOcc(vector<int>&arr, int n, int k)
{
    //first occurrence
    int start = 0;
    int end = n - 1;
    
    int firstOcc = -1;
    
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == k)
        {
            firstOcc = mid;
            end = mid - 1;
        }
        else if(arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return firstOcc;
}

int lOcc(vector<int>&arr, int n, int k)
{
    //last occurrence
    int start = 0;
    int end = n - 1;
    
    int lastOcc = -1;
    
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] == k)
        {
            lastOcc = mid;
            start = mid + 1;
        }
        else if(arr[mid] < k)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return lastOcc;
}

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    pair<int, int> ans;
    
    ans.first = fOcc(arr, n, k);
    
    ans.second = lOcc(arr, n, k);
    
    return ans;
}