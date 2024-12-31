class Solution {
public:
    unordered_map<char, string> mp {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"},
            {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if(digits.empty()){
            return result;
        }
        string word = "";
        func(digits,result,0,word);
        return result;
    }
    void func(string &digits,vector<string> &result,int idx, string &word ){
        if(idx==digits.size()){
            result.push_back(word);
        }
        for(int i=0;i<mp[digits[idx]].size();i++){
            word.push_back(mp[digits[idx]][i]);
            func(digits,result,idx+1,word);
            word.pop_back();

        }
    }
};