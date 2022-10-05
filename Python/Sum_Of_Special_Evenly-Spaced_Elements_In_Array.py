class Solution:
    def solve(self, nums: List[int], queries: List[List[int]]) -> List[int]:
        n = len(nums)
        sq = int(sqrt(n))
        mod = 1000*1000*1000+7
        m = {}
        ans = []
        for x,y in queries :
            if y > sq :
                sm = 0
                while x < n :
                    sm+=nums[x]
                    sm %= mod
                    x+=y
                ans.append(sm)
            else :
                start = x % y
                if (start,y) not in m :
                    m[(start,y)]=[0]
                    sm=0
                    curr = start
                    while curr < n :
                        sm+=nums[curr]
                        sm %= mod
                        m[(start,y)].append(sm)
                        curr+=y
                ans.append((m[(start,y)][-1]-m[(start,y)][x//y])%mod)
                
        return ans
