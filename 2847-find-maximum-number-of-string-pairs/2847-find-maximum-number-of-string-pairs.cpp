class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        map<string,int>mp;
        for(string s:words){
            string x=s;
            reverse(s.begin(),s.end());
            if(mp.find(s) !=mp.end() ){
                mp[s]++;
            }
            else if(mp.find(x) !=mp.end()){
                mp[x]++;
            }
            else{
                mp[s]++;
            }
        }
        int count=0;
        for(auto [string,f]:mp){
            count+=(f)*(f-1)/2;

        }
        return count;
    }
};