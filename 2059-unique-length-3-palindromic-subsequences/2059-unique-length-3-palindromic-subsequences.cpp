class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        unordered_map<char,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
        }
        int count=0;
        for(auto ele:mp){
            vector<int>idx=ele.second;
            int st=idx[0];
            int e=idx[idx.size()-1];
            if((e-st)<=1){
                continue;
            }
            else{
                map<char,int>mpp;
                for(int i=st+1;i<e;i++){
                    mpp[s[i]]++;
                }
                count+=mpp.size();
            }

        }
        return count;
        
    }
};