class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+nums[i];
        }
        int count=0;
        for(int i=1;i<n;i++){
            if(pf[i-1]>=pf[n-1]-pf[i-1]){
                count++;
            }
        }
        return count;
    }
};