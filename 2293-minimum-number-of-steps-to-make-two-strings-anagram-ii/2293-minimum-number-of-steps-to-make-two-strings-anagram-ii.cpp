class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        for(char c:t){
            mp[c]--;
        }
        int count=0;
        for(auto [c,f]:mp){
            if(f !=0){
                count+=abs(f);
            }
        }
        return count;
    }
};