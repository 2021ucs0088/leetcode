class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>result;
        sort(candidates.begin(),candidates.end());
        vector<int>subset;
        func(candidates,result,subset,target,0);
        return result;

    }
    void func(vector<int>& candidates,vector<vector<int>> &result,vector<int>&subset,int &target,int index){
        int x=accumulate(subset.begin(),subset.end(),0);
        if(x==target){
            if(find(result.begin(),result.end(),subset) ==result.end()){
                result.push_back(subset);

            }
            
        }
        if(x>target){
            return ;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]){
                continue;
            }
            subset.push_back(candidates[i]);
            func(candidates,result,subset,target,i+1);
            subset.pop_back();
        }
    }
};