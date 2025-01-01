class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        vector<int>subset;
        vector<vector<int>>result;
        func(result,subset,nums,k,0);
        return result.size()-1;
    }
    void func(vector<vector<int>>&result,vector<int>&subset,vector<int>& nums,int & k,int idx){
        result.push_back(subset);
        for(int i=idx;i<nums.size();i++){
            if((find(subset.begin(),subset.end(),nums[i]+k) ==subset.end()) && (find(subset.begin(),subset.end(),nums[i]-k) ==subset.end()) ){
                subset.push_back(nums[i]);
                func(result,subset,nums,k,i+1);
                subset.pop_back();
            }
        }
    }
};