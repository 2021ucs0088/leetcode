class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int r = grid.size();
        int c = grid[0].size();
        int maxArea = 0; 
        vector<int> area; 
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    int count = 0; 
                    func(i, j, grid, count);
                    area.push_back(count); 
                }
            }
        }
        
        if (area.empty()) {
            return 0;
        }
        
        return *max_element(area.begin(), area.end());
    }
    
    void func(int i, int j, vector<vector<int>>& grid, int &count) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) {
            return;
        }
        
        grid[i][j] = 0; 
        count++; 
        func(i + 1, j, grid, count);
        func(i - 1, j, grid, count);
        func(i, j + 1, grid, count);
        func(i, j - 1, grid, count);
    }
};