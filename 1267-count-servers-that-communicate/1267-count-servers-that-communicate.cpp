class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int total = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    total++;
                }
            }
        }
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    if (func(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
        return total - count;
    }
    bool func(vector<vector<int>>& grid, int row, int col) {
        int r = grid.size();
        int c = grid[0].size();

        for (int i = 0; i < r; i++) {
            if (grid[i][col] != 0 && i != row) {
                return false;
            }
        }
        for (int i = 0; i < c; i++) {
            if (grid[row][i] != 0 && i != col) {
                return false;
            }
        }
        return true;
    }
};