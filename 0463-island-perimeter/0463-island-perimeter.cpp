class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    for (auto d : dir) {
                        int newx = i + d[0];
                        int newy = j + d[1];
                        if(newx>=0 && newy>=0 && newx<r && newy<c && grid[newx][newy]==1){
                            ans-=1;

                        }
                    }
                }
            }
        }
        return ans;
    }
};