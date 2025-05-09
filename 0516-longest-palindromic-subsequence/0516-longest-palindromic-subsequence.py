class Solution:
    def longestPalindromeSubseq(self, s: str) -> int:
        n=len(s)
        dp=[[0]*n for _ in range(n)]
        for i in range(n):
            dp[i][i]=1
        for l in range(2,n+1):
            for i in range(0,n-l+1):
                j=i+l-1
                if s[i]==s[j] and l==2:
                    dp[i][j]=2
                elif s[i]==s[j]:
                    dp[i][j]=2+dp[i+1][j-1]
                else:
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1])
        return dp[0][n-1]

