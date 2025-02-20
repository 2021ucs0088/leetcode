class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        for (int i = 0; i < n; i++) {
            if (islower(word[i])) {
                word[i] = '0';
            } else {
                word[i] = '1';
            }
        }
        set<char> s;
        for (int i = 1; i < n; i++) {
            s.insert(word[i]);
        }
        if (word[0] == '1') {
            if(s.size()==1){
                return true;
            }
            else{
                return false;
            }

        } else {
            if(s.size()==1){
                for(char c:s){
                    if(c=='0'){
                        return true;
                    }
                    else{
                        return false;
                    }
                }

            }else{
                return false;
            }
        }
        return false;
    }
};