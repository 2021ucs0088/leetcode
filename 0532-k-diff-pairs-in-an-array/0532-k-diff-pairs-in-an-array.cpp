class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int ans=0;
        for(auto t:mp){
            if(k==0){
                if(t.second>1){
                    ans++;
                }

            }
            else {
                if(mp.find(t.first+k) !=mp.end()){
                    ans++;
                }


            }
        }
        return ans;
    }
};