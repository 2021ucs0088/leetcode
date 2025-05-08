class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>v1(26);
        vector<int>v2(26);
        for(char c:s){
            v1[c-'a']++;
        }
        for(char c:t){
            v2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(v1[i]!=v2[i]){
                return false;
            }
        }
        return true;

    }
};