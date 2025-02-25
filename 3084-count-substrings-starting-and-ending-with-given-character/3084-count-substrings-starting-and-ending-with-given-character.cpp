class Solution {
public:
    long long countSubstrings(string s, char c) {
        map<char,int>mp;
        for (char ch:s){
            mp[ch]++;
        }
        long long  x=mp[c];
        return static_cast<long long>(x*(x+1))/2;
    }
};