class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        for(int i=0;i<r;i++){
            set<int>row;
            set<int>col;
            for(int j=0;j<c;j++){
                row.insert(matrix[i][j]);
                col.insert(matrix[i][j]);

            }
            if(row.size()!=r || col.size()!=c){
                return false;
            }
        }
        return true;
    }

};