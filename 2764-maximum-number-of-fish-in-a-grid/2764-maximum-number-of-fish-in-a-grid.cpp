class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        int maxval=INT_MIN;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    int count=0;
                    func(i,j,grid,count);
                    maxval=max(maxval,count);
                }
            }
        }
        if (maxval==INT_MIN){
            return 0;
        }
        return maxval;

    }
    void func(int i,int j,vector<vector<int>>& grid ,int &count){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0){
            return ;

        }
        count+=grid[i][j];
        grid[i][j]=0;
        func(i+1,j,grid,count);
        func(i-1,j,grid,count);
        func(i,j-1,grid,count);
        func(i,j+1,grid,count);
    }

};