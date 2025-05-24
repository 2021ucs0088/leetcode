class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mp;
        long long pf=0;
        mp[0]=-1;
        for (int i=0;i<n;i++){
            pf+=nums[i];
            int cmod=((pf%k)+k)%k;
            if ((mp.find(cmod) !=mp.end())){
                if (i-mp[cmod] >1){
                    return true;
                }
                
                

            }
            else{
                    mp[cmod]=i;
                }
            
            
            

        }
        return false;
        
    }
};