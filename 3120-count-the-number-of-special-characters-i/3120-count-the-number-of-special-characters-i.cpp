class Solution {
public:
    int numberOfSpecialChars(string word) {
        int n=word.size();
        set<char>s(word.begin(),word.end());
        map<char,int>mp;
        for(char c:s){
            mp[tolower(c)]++;
        }
        int count=0;
        for(auto [c,f]:mp){
            if(f==2){
                count++;
            }
        }
        return count;

    }
};