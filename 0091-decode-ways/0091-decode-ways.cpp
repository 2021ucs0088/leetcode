class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        if (s[0]=='0'){
            return 0;
        }
        dp[0]=1;
        dp[1]=1;
        for (int i=2;i<=n;i++){
            int two=stoi(s.substr(i-2,2));
            if (s[i-1]=='0'){
                if (two>=10 && two<=26){
                    dp[i]+=dp[i-2];
                }
                
            }
            else{
                if (two>=10 && two<=26){
                    dp[i]+=dp[i-1]+dp[i-2];
                }
                else{
                    dp[i]+=dp[i-1];

                }
                

                

            }
        }
        return dp[n];




        

        

    }
};