class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        if (s.empty()){
            return 0;
        }
        int left=0;
        int right=0;
        int n=s.size();
        int ans=INT_MIN;
        for(int right=0;right<n;right++){
            while(mp.find(s[right]) !=mp.end()){
                mp.erase(s[left]);
                left++;
            }
            ans=max(ans,right-left+1);
            mp[s[right]]++;
        }
        return ans;
        
    }
};