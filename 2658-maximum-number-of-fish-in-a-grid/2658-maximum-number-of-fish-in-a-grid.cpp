class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        queue<pair<int,int>>q;
        if(grid.empty()){
            return 0;
        }
        int r=grid.size();
        int c=grid[0].size();
        vector<int>result;
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    count=grid[i][j];
                    q.push({i,j});
                    grid[i][j]=0;
                }
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(auto d:dir){
                        int newx=x+d[0];
                        int newy=y+d[1];
                        if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy] !=0){
                            count+=grid[newx][newy];
                            grid[newx][newy]=0;
                            q.push({newx,newy});
                        }
                    }
                }
                result.push_back(count);
            }
        }
        return *max_element(result.begin(),result.end());
    }
};