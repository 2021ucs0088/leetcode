class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pf(n);
        pf[0]=nums[0];
        int count=0;
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+nums[i];
        }
        long long first=0;
        long long second=0;
        for(int i=0;i<n-1;i++){
            first=pf[i];
            second=pf[n-1]-pf[i];
            if(first>=second){
                count++;
            }
            
        }
        return count;
    }
};