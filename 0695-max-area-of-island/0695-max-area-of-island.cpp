class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid.empty()){
            return 0;
        }
        queue<pair<int,int>>q;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        vector<int>area;
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    grid[i][j]=0;
                    count=1;
                }
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(auto d:dir){
                        int newx=x+d[0];
                        int newy=y+d[1];
                        if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy] !=0){
                            q.push({newx,newy});
                            count++;
                            
                            grid[newx][newy]=0;
                        }
                        
                    }
                    

                }
                area.push_back(count);
            }
        }
        return *max_element(area.begin(),area.end());
    }
};