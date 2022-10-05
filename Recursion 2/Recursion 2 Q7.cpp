int binarySearchRec(int *input, int start, int end, int key)
{
    if(start > end)
    {
        return -1;
    }
    
    int mid = start + (end - start) / 2;
    
    if(input[mid] == key)
    {
        return mid;
    }
    
    if(input[mid] < key)
    {
        binarySearchRec(input, mid + 1, end, key);
    }
    else
    {
         binarySearchRec(input, start, mid - 1, key);
    }
}

int binarySearch(int *input, int n, int val)
{
    int ans = binarySearchRec(input, 0, n - 1, val);
    
    return ans;
}