class Solution {
public:
    int minSteps(string s, string t) {
        map<char,int>mp;
        for(char i:s){
            mp[i]++;
        }
        for(int i:t ){
            mp[i]--;
        }
        int count=0;
        for(auto [c,f]:mp){
            if(f>0){
                count+=f;
            }
        }
        return count;
    }
};