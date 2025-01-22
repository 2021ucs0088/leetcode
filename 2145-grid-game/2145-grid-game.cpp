class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<long long> pf(n + 1, 0);  // Use long long for prefix sum
        for (int i = 1; i <= n; i++) {
            pf[i] = pf[i - 1] + grid[0][i - 1];
        }
        vector<long long> pf2(n + 1, 0); // Use long long for prefix sum
        for (int i = 1; i <= n; i++) {
            pf2[i] = pf2[i - 1] + grid[1][i - 1];
        }
        
        long long total = LLONG_MAX; // Initialize to a large value to find the minimum
        for (int i = 1; i <= n; i++) {
            long long x = pf[n] - pf[i];   // Top row remaining sum after i
            long long y = pf2[i - 1];     // Bottom row sum before i
            total = min(total, max(x, y)); // Minimize the maximum score of the second robot
        }
        return total;
    }
};
