class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if (sum%k !=0){
            return false;
        }
        int target=sum/k;
        sort(nums.rbegin(),nums.rend());
        if (nums[0]>target){
            return false;
        }
        int n=nums.size();
        vector<bool>visit(n,false);
        return func(nums,k,0,visit,target,0);


    }
    bool func(vector<int>& nums, int  k,int start,vector<bool>&visit,int target,int currentsum){
        if (k==0){
            return true;
        }
        if (currentsum==target){
            return func(nums,k-1,0,visit,target,0);
        }
        for (int i=start;i<nums.size();i++){
            if (!visit[i] && currentsum+nums[i]<=target){
                visit[i]=true;
                if (func(nums,k,i+1,visit,target,currentsum+nums[i])){
                    return true;
                }
                visit[i]=false;
            }
        }
        return false;

    }
};