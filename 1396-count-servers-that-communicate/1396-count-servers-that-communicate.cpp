class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        vector<int> v1(r);
        vector<int> v2(c);
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    v1[i]++;
                    v2[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if ( grid[i][j]==1 && (v1[i] >1  || v2[j] > 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};