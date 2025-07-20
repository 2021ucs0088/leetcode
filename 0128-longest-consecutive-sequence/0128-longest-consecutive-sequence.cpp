class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]=1;
        }
        int ans=0;
        while(!mp.empty()){
            int first=mp.begin()->first;
            int count=1;
            mp.erase(first);
            while(mp.find(first+1)!=mp.end()){
                count++;
                mp.erase(first);
                first++;
            }
            ans=max(ans,count);

        }
        return ans;
    }
};