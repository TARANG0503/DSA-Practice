/*Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
https://leetcode.com/problems/contains-duplicate/

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true

Input: nums = [1,2,3,4]
Output: false
*/

class Solution {
    public boolean containsDuplicate(int[] nums) {
        /*HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++){
            if(!map.containsKey(nums[i])){
                map.put(nums[i],1);
            }
            else{
                return true;
                }
            }
        return false;
        }*/
        
        int ans = nums[nums.length-1];
        for(int i=0;i<=nums.length-2;i++){
            if(ans==nums[i]){
                return true;
            }
            else{
                nums[nums.leng]
            }
        }
    }
/*for(Map.Entry m : map.entrySet){
                    map.put(nums[i],map.getValue(nums[i])+1);*/
