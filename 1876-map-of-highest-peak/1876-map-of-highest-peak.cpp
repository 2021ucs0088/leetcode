class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r=isWater.size();
        int c=isWater[0].size();
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<vector<int>>dp(r,vector<int>(c,INT_MAX));
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(isWater[i][j]==1){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto d:dir){
                int newx=x+d[0];
                int newy=y+d[1];
                if(newx>=0 && newy>=0 && newx<r && newy<c && isWater[newx][newy]==0){
                    dp[newx][newy]=min(dp[newx][newy],dp[x][y]+1);
                    isWater[newx][newy]=1;
                    q.push({newx,newy});
                }
            }
        }
        return dp;

    }
};