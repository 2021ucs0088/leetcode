class Solution:
    def nthUglyNumber(self, n: int) -> int:
        dp=[0]*n
        dp[0]=1
        i5=0
        i2=0
        i3=0
        for i in range(1,n):
            nextval=min(dp[i2]*2,dp[i3]*3,dp[i5]*5)
            dp[i]=nextval
            if nextval==dp[i2]*2:
                i2=i2+1
            if nextval==dp[i3]*3:
                i3=i3+1
            if nextval==dp[i5]*5:
                i5=i5+1
        return dp[n-1]

        