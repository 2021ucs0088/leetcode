class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        vector<int>dp(n,1);
        for (int i=1;i<n;i++){
            for (int j=0;j<i;j++){
                if (arr[i]-arr[j]==difference){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return dp[n-1];
    }
};