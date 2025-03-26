class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>pf(n,1);
        vector<int>sf(n,1);
        pf[0]=nums[0];
        sf[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]*nums[i];
        }
        for(int i=n-2;i>=0;i--){
            sf[i]=sf[i+1]*nums[i];
        }
        vector<int>result(n);
        result[0]=sf[1];
        result[n-1]=pf[n-2];
        for(int i=1;i<=n-2;i++){
            result[i]=pf[i-1]*sf[i+1];

        }
        return result;
    }
};