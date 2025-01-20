class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        vector<int>row0(r);
        vector<int>row1(r);
        vector<int>col0(c);
        vector<int>col1(c);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==0){
                    row0[i]++;
                    col0[j]++;
                }
                else{
                    row1[i]++;
                    col1[j]++;


                }
            }
        }
        vector<vector<int>>ans(r,vector<int>(c));
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j]=row1[i]+col1[j]-row0[i]-col0[j];
            }
        }
        return ans;


    }
};