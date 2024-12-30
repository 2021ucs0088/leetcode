class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int curmin=nums[0];
        int curmax=nums[0];
        int result=nums[0];
        for (int i=1 ; i<n ; i++){
            int temp=curmax;
            curmax=max(nums[i],max(curmax*nums[i],curmin*nums[i]));
            curmin=min(nums[i],min(curmin*nums[i],temp*nums[i]));
            result=max(result,curmax);
        }
        return result;
        
    }
};