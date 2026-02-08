class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        for(int num:nums){
            total+=num;
        }
        if(abs(target)>total){
            return 0;
        }
        int sum=total+target;
        if(sum%2!=0){
            return 0;
        }
        sum=sum/2;
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int num:nums){
            for(int i=sum;i>=0;i--){
                if(i-num>=0){
                    dp[i]+=dp[i-num];
                }

            }
        }
        return dp[sum];
        

    }
};