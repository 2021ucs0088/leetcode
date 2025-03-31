class Solution {
    public int countSubstrings(String s) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        int count = 0;
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }
        for (int l = 2; l <= n; l++) {
            for (int st = 0; st <= n - l; st++) {
                int end = st + l - 1;
                if (func(s, st, end, dp)) {
                    count++;
                }
            }
        }
        return count;

    }

    boolean func(String s,int i,int j,boolean [][]dp){
        if(i==j){
            dp[i][j]=true;
        }
        if(j-i==1 && s.charAt(i)==s.charAt(j)){
            dp[i][j]=true;

        }
        else{
            if(s.charAt(i)==s.charAt(j)){
                if(dp[i+1][j-1]){
                    dp[i][j]=true;
                }



            }
            else{
                dp[i][j]=false;
            }
        }
        return dp[i][j];
    }

}