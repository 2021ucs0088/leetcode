class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        vector<int>subset;
        func(nums,result,subset,0);
        return result;
    }
    void func(vector<int>& nums,vector<vector<int>> &result,vector<int>&subset,int index){
        if(find(result.begin(),result.end(),subset) ==result.end()){
            result.push_back(subset);
        }
        for(int i=index;i<nums.size();i++){
            subset.push_back(nums[i]);
            func(nums,result,subset,i+1);
            subset.pop_back();
        }
    }
};