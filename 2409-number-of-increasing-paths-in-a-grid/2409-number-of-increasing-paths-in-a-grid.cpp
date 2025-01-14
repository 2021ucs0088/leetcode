class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int mod=1e9+7;
        int r=grid.size();
        int c=grid[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=(ans+func(i,j,dp,dir,grid))%mod;
            }
        }
        return ans;

    }
    int func(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&dir ,vector<vector<int>>& grid){
        int r=grid.size();
        int c=grid[0].size();
        int mod=1e9+7;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        dp[i][j]=1;
        for(auto d:dir){
            int newx=i+d[0];
            int newy=j+d[1];
            if(newx>=0 && newy>=0 && newx<r && newy<c){
                if(grid[newx][newy]>grid[i][j]){
                    dp[i][j]=(dp[i][j]+func(newx,newy,dp,dir,grid))%mod;
                }
            }
        }
        return dp[i][j];
    }
};