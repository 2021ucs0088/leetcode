class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int count=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]=='1'){
                    count++;
                    func(i,j,grid);
                }
            }
        }
        return count;

    }
    void func(int i ,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]=='0'){
            return ;
        }
        grid[i][j]='0';
        func(i+1,j,grid);
        func(i-1,j,grid);
        func(i,j+1,grid);
        func(i,j-1,grid);
    }
};