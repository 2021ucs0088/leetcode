class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pf(n);
        pf[0]=nums[0];
        for(int i=1;i<n;i++){
            pf[i]=pf[i-1]+nums[i];
        }
        int index=-1;
        int mindiff=INT_MAX;
        for(int i=0;i<n;i++){
            int left=pf[i]/(i+1);
            int right=(i==n-1)?0 :(pf[n-1]-pf[i])/(n-i-1);
            if(abs(left-right)<mindiff){
                index=i;
                mindiff=abs(left-right);
            }
            

        }
        return index;
    }
};