class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        vector<int>result;
        for(auto [x,f]:mp){
            if(f==2){
                result.push_back(x);
            }
        }
        return result;
    }
};