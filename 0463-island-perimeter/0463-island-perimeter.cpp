class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int result=0;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                if (grid[i][j]==1){
                    result+=4;
                    for (auto d:dir){
                        int newr=i+d[0];
                        int newc=j+d[1];
                        if (newr>=0 && newc>=0 && newr<r && newc<c && grid[newr][newc] ==1 ){
                            
                            result-=1;

                        }
                        
                    }
                }
            }
        }
        return result;
    }
};