class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        unordered_map<char,int>mp;
        int maxl=0;
        for(int right=0;right<n;right++){
            if(mp.find(s[right]) !=mp.end()){
                while(mp.find(s[right]) !=mp.end()){
                    mp.erase(s[left]);
                    left++;
                }
            }
            mp[s[right]]++;
            maxl=max(maxl,right-left+1);
            



        }
        return maxl;
    }
};