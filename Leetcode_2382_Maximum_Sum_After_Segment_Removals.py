class UnionFind :
    def __init__(self):
        self.parent = {}
        self.maxsum = 0
        self.sum = {}
        
    def find(self,x):
        if x!=self.parent[x]:
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]
    
    def union(self,x,y):
        px = self.find(x)
        py = self.find(y)
        if px==py :
            return
        self.sum[px]+=self.sum[py]
        self.parent[py]=px
        self.maxsum = max(self.maxsum,self.sum[px])
    
    def mergesegment(self,u,value):
        self.parent[u]=u
        self.maxsum = max(self.maxsum,value)
        self.sum[u]=value
        if u-1 in self.parent :
            self.union(u-1,u)
        if u+1 in self.parent :
            self.union(u+1,u)
        
class Solution:
    def maximumSegmentSum(self, nums, removeQueries):
        uf = UnionFind()
        n = len(nums)
        ans = [0]*n
        for i in range(n-1,-1,-1):
            ans[i] = uf.maxsum
            q = removeQueries[i]
            uf.mergesegment(q,nums[q])
        return ans
