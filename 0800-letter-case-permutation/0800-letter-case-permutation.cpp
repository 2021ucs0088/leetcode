class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string>result;
        string word="";
        func(result,s,word,0);
        return result;

    }
    void func(vector<string> &result,string & s,string &word,int index){
        if (word.size()==s.size()){
            result.push_back(word);
            return ;
        }
        for(int i=index;i<s.size();i++){
            if(isdigit(s[i])){
                word+=s[i];
                func(result,s,word,i+1);
                word.pop_back();
            }
            else{
                char u=toupper(s[i]);
                char l=tolower(s[i]);
                word+=u;
                func(result,s,word,i+1);
                word.pop_back();
                word+=l;
                func(result,s,word,i+1);
                word.pop_back();



            }
        }
    }
};