class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int inc=1;
        int dec=1;
        int maxl=1;
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                inc++;
                maxl=max(maxl,inc);
                
            }
            else if(nums[i]<nums[i+1]){
                dec++;
                maxl=max(maxl,dec);
            }
            else{
                inc=1;
                dec=1;
            }
        }
        return maxl;
    }
};