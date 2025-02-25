class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        int open = 0;
        int close = 0;
        string word = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') {
                word += s[i];
            } else {
                if (s[i] == '(') {
                    open++;
                }
                if (s[i] == ')') {
                    close++;
                }
                if(open>=close){
                    word+=s[i];
                    
                }
                else{
                    close--;
                }
                
            }
        }
        string result="";
        int m=word.size();
        open=0;
        close=0;
        for(int i=m-1;i>=0;i--){
            if(word[i] !='(' && word[i] !=')'){
                result+=word[i];
            }
            else{
                if(word[i]=='('){
                    open++;
                }
                if(word[i]==')'){
                    close++;
                }
                if(close>=open){
                    result+=word[i];
                    
                }
                else{
                    open--;
                }
                

            }

        }
        reverse(result.begin(),result.end());
        return result;
    }
};