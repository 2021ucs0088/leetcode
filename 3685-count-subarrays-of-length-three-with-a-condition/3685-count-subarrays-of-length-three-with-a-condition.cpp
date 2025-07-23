class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int  n=nums.size();
        int ans=0;
        for(int i=1;i<n-1;i++){
            int left=i-1;
            int right=i+1;
            if(nums[i]==(nums[left]+nums[right])*2){
                ans++;
            }

        }
        return ans;
    }
};