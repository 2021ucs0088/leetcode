class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=INT_MIN;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,func(i,j,matrix,dir,dp));

            }
        }
        return ans+2;
    }
    int func(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>&dir,vector<vector<int>>&dp){
        int r=matrix.size();
        int c=matrix[0].size();
        if (dp[i][j]!=-1){
            return dp[i][j];
        }
        for(auto d:dir){
            int newx=i+d[0];
            int newy=j+d[1];
            if(newx>=0 && newy>=0 && newx<r && newy<c){
                if(matrix[newx][newy]>matrix[i][j]){
                    dp[i][j]=max(func(newx,newy,matrix,dir,dp)+1,dp[i][j]);
                }
                
            }
        }
        return dp[i][j];
    }
};