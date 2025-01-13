class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int fresh = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int time = 0;
        while (!q.empty()) {
            int size = q.size();
            bool rotten =false;
            for (int i = 0; i < size; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto d:dir){
                    int newx=x+d[0];
                    int newy=y+d[1];
                    if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy]==1){
                        grid[newx][newy]=2;
                        fresh--;
                        q.push({newx,newy});
                        rotten=true;
                    }

                }
                
            }
            if(rotten==true){
                    time++;
                }
        }
        if(fresh==0){
            return time;
        }
        return -1;
    }
};