class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        map<char,int>mp;
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]<0){
                    mp['n']++;
                }
            }
        }
        return mp['n'];
    }
};