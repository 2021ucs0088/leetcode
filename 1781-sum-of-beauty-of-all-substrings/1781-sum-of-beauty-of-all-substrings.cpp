class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<char,int>mp;
            for(int j=i;j<n;j++){
                mp[s[j]]++;
                int maxf=INT_MIN;
                int minf=INT_MAX;
                for(auto [c,f]:mp){
                    maxf=max(maxf,f);
                    minf=min(minf,f);
                }
                ans+=maxf-minf;

            }

        }
        return ans;
    }
};