class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>>mp;
        for(string s:strs){
            string x=s;
            sort(x.begin(),x.end());
            mp[x].push_back(s);
        }
        vector<vector<string>>result;
        for(auto x:mp){
            result.push_back(x.second);
        }
        return result;
    }
};