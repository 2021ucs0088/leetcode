class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<int>ans;
        for(auto [x,f]:mp){
            if(f==2){
                ans.push_back(x);
            }
        }
        return ans;
    }
};