class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>result(n);
        int pf=0;
        for(int i=0;i<n;i++){
            pf=(pf*2+nums[i])%5;
            result[i]=(pf==0);

        }
        return result;

    }
};