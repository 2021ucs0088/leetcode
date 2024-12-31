class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>subset;
        func(result,subset,nums);
        return result;

    }
    void func(vector<vector<int>>&result,vector<int>&subset,vector<int>& nums){
        if(subset.size()==nums.size()){
            result.push_back(subset);
        }
        for(int i=0;i<nums.size();i++){
            if(find(subset.begin(),subset.end(),nums[i]) ==subset.end()){
                subset.push_back(nums[i]);
                func(result,subset,nums);
                subset.pop_back();
            }
            

        }
    }
};