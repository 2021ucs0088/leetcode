class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        vector<int>subset;
        func(candidates,result,subset,target,0);
        return result;
    }
    void func(vector<int>& candidates,vector<vector<int>>&result,vector<int>&subset,int &target,int index){
        int x=accumulate(subset.begin(),subset.end(),0);
        if(x==target){
            result.push_back(subset);
            
        }
        if(x>target){
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            subset.push_back(candidates[i]);
            func(candidates,result,subset,target,i);
            subset.pop_back();

        }
    }
};