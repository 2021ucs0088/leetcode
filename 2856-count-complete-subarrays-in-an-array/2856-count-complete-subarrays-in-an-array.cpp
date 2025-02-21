class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        int d=mp.size();
        int left=0;
        int right=0;
        int ans=0;
        unordered_map<int,int>freq;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(freq.size()==d){
                ans+=n-right;
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;

            }

        }
        return ans;

        

    }
};