class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int r = isWater.size();
        int c = isWater[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> result(r, vector<int>(c, INT_MAX - 1));
        
        // Initialize water cells
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (isWater[i][j] == 1) {
                    q.push({i, j});
                    result[i][j] = 0;
                }
            }
        }

        // Directions for BFS
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        
        // BFS traversal
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto d : dir) {
                int newx = x + d[0];
                int newy = y + d[1];
                if (newx >= 0 && newy >= 0 && newx < r && newy < c && result[newx][newy] == INT_MAX - 1) {
                    result[newx][newy] = result[x][y] + 1;
                    q.push({newx, newy});
                }
            }
        }

        return result;
    }
};
