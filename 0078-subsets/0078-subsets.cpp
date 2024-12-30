class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>result;
        vector<int>subset;
        func(nums,result,subset,0);
        return result;

    }
    void func(vector<int>& nums,vector<vector<int>>&result,vector<int>&subset,int start){
        result.push_back(subset);
        for (int i=start;i<nums.size();i++){
            subset.push_back(nums[i]);
            func(nums,result,subset,i+1);
            subset.pop_back();

        }
    }
};