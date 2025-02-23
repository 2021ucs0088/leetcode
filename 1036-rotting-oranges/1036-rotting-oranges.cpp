class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int empty=0;
        int fresh=0;
        int rotten=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    empty++;
                }
                if(grid[i][j]==1){
                    fresh++;
                }
                if(grid[i][j]==2){
                    rotten++;
                }
            }
        }
        if(rotten ==0  && fresh==0){
            return 0;


        }
        if(rotten ==0 && fresh!=0){
            return -1;

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