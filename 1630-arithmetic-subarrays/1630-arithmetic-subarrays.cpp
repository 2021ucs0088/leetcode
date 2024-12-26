class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int n = l.size();
        vector<bool> ans;
        for (int i = 0; i < n; i++) {
            vector<int> subarray(nums.begin() + l[i], nums.begin() + r[i] + 1); // Fixed range
            ans.push_back(func(subarray));
        }
        return ans;
    }

    bool func(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int diff = nums[1] - nums[0];
        for (int i = 2; i < nums.size(); i++) {
            if (nums[i] - nums[i - 1] != diff) {
                return false;
            }
        }
        return true;
    }
};
