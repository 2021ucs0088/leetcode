class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        map<int,int>mp;
        vector<int>ans;
        for(int num:nums){
            mp[num]++;
        }
        for(auto [x,f]:mp){
            if(f==1){
                ans.push_back(x);
            }
        }
        return ans;
    }
};