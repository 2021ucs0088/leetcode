class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int d=mp.size();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_set<int>temp;
            for(int j=i;j<n;j++){
                temp.insert(nums[j]);
                if(temp.size()==d){
                    ans++;
                }

            }
        }
        return ans;

    }
};