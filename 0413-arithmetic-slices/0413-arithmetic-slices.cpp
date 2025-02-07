class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if (n<3){
            return 0;
        }
        vector<int>dp(n,0);
        dp[0]=0;
        dp[1]=0;
        for (int i=2;i<n;i++){
            if (nums[i-2]-nums[i-1]==nums[i-1]-nums[i]){
                dp[i]=dp[i-1]+1;
            }
        }
        int ans=accumulate(dp.begin(),dp.end(),0);
        return ans;




    }
};