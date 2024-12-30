class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n);
        int result=nums[0];
        int currentmax=nums[0];
        int currentmin=nums[0];
        for (int i=1;i<n;i++){
            int temp=currentmax;
            currentmax=max(nums[i],max(currentmax*nums[i],currentmin*nums[i]));
            currentmin=min(nums[i],min(temp*nums[i],currentmin*nums[i]));





            result=max({result,currentmax,currentmin});
        }
        return result;
    }
};