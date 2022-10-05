//Peak Index in a Mountain Array using recursion
class Solution {
public:
    void mountainPeak(vector<int>& arr, int start, int end, int& peak)
    {
        if(start > end)
        {
            return;
        }
        
        int mid = start + (end - start) / 2;
            
        if(arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
        {
            peak = mid;
        }
            
        else if(arr[mid] < arr[mid + 1])
        {
            mountainPeak(arr, mid + 1, end, peak);
        }
            
        else
        {
            mountainPeak(arr, start, mid, peak);
        }
    }
    
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int peak = 0;
        
        mountainPeak(arr, 0, arr.size() - 1, peak);
        
        return peak;
       
    }
};