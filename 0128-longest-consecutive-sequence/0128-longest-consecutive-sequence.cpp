class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]=1;
        }
        if(nums.size()==0){
            return 0;
        }
        int maxl=1;
        while(!mp.empty()){
            int first=mp.begin()->first;
            int current=1;
            mp.erase(first);
            while(mp.find(first+1) !=mp.end()){
                first++;
                mp.erase(first);
                
                current++;

            }
            maxl=max(maxl,current);
        }
        return maxl;

    }
};