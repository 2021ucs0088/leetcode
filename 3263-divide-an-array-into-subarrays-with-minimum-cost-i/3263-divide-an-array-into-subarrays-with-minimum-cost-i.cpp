class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int first=nums[0];
        sort(nums.begin()+1,nums.end());
        int second=nums[1];
        int third=nums[2];
        return first+second+third;
    }
};