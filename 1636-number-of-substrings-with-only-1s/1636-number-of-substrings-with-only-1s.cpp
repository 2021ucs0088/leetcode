class Solution {
public:
    int numSub(string s) {
        long long ans=0;
        long long count=0;
        long long mod=1e9+7;
        for(char c:s){
            if(c=='1'){
                count++;
                ans=(ans+count)%mod;
            }
            else{
                count=0;
            }
        }
        return ans;
    }
};