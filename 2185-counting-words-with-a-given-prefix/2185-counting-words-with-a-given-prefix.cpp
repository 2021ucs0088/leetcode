class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int count=0;
        for(auto ele :words){
            string str=ele.substr(0,n);
            if(str==pref){
                count++;
            }
        }
        return count;
    }
};