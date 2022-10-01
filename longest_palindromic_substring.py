class Solution:
	def longestPalindrome(self, s: str) -> str:
		n=len(s)
		res=''
		for i in range(len(s)):
			if len(res)<len(self.helper(s,i,i)):
				res=self.helper(s,i,i)
			if len(res)<len(self.helper(s,i,i+1)):
				res=self.helper(s,i,i+1)
		return res
	def helper(self,s,l,r):
		while(l>=0 and r<len(s) and s[l]==s[r]):
			l-=1
			r+=1
		return s[l+1:r]
