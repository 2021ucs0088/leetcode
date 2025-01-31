class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int>pf(n+1);
        for(int i=1;i<=n;i++){
            pf[i]=pf[i-1]+func(words[i-1]);
        }
        vector<int>result(queries.size());
        for(int i=0;i<queries.size();i++){
            result[i]=pf[queries[i][1]+1]-pf[queries[i][0]];
        }
        return result;
    }
    bool func(string s){
        int n=s.size();
        if(n==1){
            if(s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u' ){
                return true;
            }
        }
        else{
            if((s[0]=='a' || s[0]=='e' || s[0]=='i' || s[0]=='o' || s[0]=='u') && (s[n-1]=='a' || s[n-1]=='e' || s[n-1]=='i' || s[n-1]=='o' || s[n-1]=='u')){
                return true;
            }
        }
        return false;
    }
};