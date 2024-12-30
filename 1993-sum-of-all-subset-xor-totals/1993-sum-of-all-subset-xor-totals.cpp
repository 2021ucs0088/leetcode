class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        return func(0,0,nums);
    }
    int func(int result,int index,vector<int>& nums){
        if (index==nums.size()){
            return result;
        }

        int include=func(result^nums[index],index+1,nums);
        int notinclude=func(result,index+1,nums);
        return include+notinclude;
    }
};