class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        map<int,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int ans=0;
        for(auto [x,f]:mp){
            ans=max(ans,f);
        }
        return ans;
    }
};