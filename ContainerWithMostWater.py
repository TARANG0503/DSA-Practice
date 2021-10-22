class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_vol = float('-inf')
        l,r = 0, len(height)-1
        
        while l < r:
            max_vol = max(max_vol, (r-l)*min(height[l],height[r]))
            if height[l]>height[r]:
                r -= 1
            else:
                l += 1
        
        return max_vol
