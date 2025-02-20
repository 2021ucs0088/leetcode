class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int maxl=nums[0];
        int current=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                current+=nums[i];
                maxl=max(maxl,current);


            }
            else{
                current=nums[i];

            }
        }
        return maxl;
        
    }
};