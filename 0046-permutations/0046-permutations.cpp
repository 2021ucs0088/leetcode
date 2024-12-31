class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>result;
        vector<int>path;
        func(result,path,nums,0);
        return result;
        
    }
    void func(vector<vector<int>>&result,vector<int>&path,vector<int>& nums,int start){
        if (path.size()==nums.size()){
            result.push_back(path);
        }
        for (int i=start;i<nums.size();i++){
            if (find(path.begin(),path.end(),nums[i]) ==path.end()){
                path.push_back(nums[i]);
                func(result,path,nums,start);
                path.pop_back();

            }
        }

    }
};