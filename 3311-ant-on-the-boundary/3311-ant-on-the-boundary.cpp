class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+nums[i];
        }
        int count=0;
        for(int i=0;i<n;i++){
            if(pf[i]==0){
                count++;
            }
        }
        return count;
    }
};