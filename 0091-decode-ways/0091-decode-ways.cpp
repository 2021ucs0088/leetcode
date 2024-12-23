class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') {
            return 0;
        }

        vector<int> dp(n, 0);
        dp[0] = 1;

        for (int i = 1; i < n; i++) {
            if (s[i] != '0') {
                dp[i] = dp[i - 1];
            }

            int twoDigit = stoi(s.substr(i - 1, 2));
            if (twoDigit >= 10 && twoDigit <= 26) {
                if (i > 1) {
                    dp[i] += dp[i - 2];
                } else {
                    dp[i] += 1;
                }
            }
        }

        return dp[n - 1];
    }
};
