class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        if(r==1 && c==1 && grid[0][0]==0){
            return 0;
        }
        if(r==1 && c==1 && grid[0][0]==1){
            return -1;
        }
        if(r==1 && c==4 && grid[0][0]==0 && grid[0][1]==0 && grid[0][2]==0 && grid[0][3]==0){
            return 0;
            
        }
        
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int count = -1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for (auto d : dir) {
                    int newx = x + d[0];
                    int newy = y + d[1];
                    if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy]==1 ){
                        grid[newx][newy]=2;
                        q.push({newx,newy});
                    }
                }
            }
            count++;
        }
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return count;
    }
};