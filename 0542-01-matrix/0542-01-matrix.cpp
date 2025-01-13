class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==1){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dp(r,vector<int>(c,INT_MAX-1));
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(mat[i][j]==0){
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
                if(newx>=0 && newy>=0 && newx<r && newy<c){
                    dp[x][y]=min(dp[x][y],dp[newx][newy]+1);
                    
                }
            }


        }
        return dp;
        

    }
};