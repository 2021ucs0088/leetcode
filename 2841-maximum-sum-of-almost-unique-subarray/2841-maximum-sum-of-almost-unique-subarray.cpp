class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        map<int,int>mp;
        int n=nums.size();
        long long maxsum=INT_MIN;
        long long current=0;
        for(int i=0;i<k;i++){
            current+=nums[i];
            mp[nums[i]]++;
        }
        if(mp.size()>=m){
            maxsum=max(maxsum,current);
        }
        for(int i=k;i<n;i++){
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            mp[nums[i]]++;
            if(mp.size()>=m){
                current=current+nums[i]-nums[i-k];
                maxsum=max(maxsum,current);

            }
            
        }
        return maxsum==INT_MIN ?0 :maxsum;
    }
};