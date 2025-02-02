class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k){
            return false;
        }
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int odd_count=0;
        for(auto [c,f]:mp){
            if(f%2!=0){
                odd_count++;
            }
            
        }
        return odd_count<=k;
    }
};