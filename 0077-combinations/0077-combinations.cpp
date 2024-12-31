class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>result;
        vector<int>subset;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            nums[i]=i+1;
        }
        func(result,subset,nums,0,k);
        return result;
    }
    void func(vector<vector<int>>&result,vector<int>&subset,vector<int>&nums,int idx,int &k){
        if(subset.size()==k){
            result.push_back(subset);
        }
        for(int i=idx;i<nums.size();i++){
            subset.push_back(nums[i]);
            func(result,subset,nums,i+1,k);
            subset.pop_back();
        }
    }
};