// Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
// We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
// You must solve this problem without using the library's sort function.

class SortColors {
    public void sortColors(int[] nums) {
        int n=nums.length;
        int lo=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                nums[mid++]=1;
                nums[lo++]=0;
                
            }
            else if(nums[mid]==1)mid++;
            else {
                nums[mid]=nums[high];
                nums[high--]=2;
            }
        }
    }
}
