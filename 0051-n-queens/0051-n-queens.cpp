class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>result;
        vector<string>board(n,string(n,'.'));
        func(result,board,n,0);
        return  result;


        
    }
    bool is_valid(int row,int col,vector<string>& board,int n){
        for (int i=0;i<n;i++){
            if (board[i][col]=='Q'){
                return false;
            }
        }
        for (int i=0;i<n;i++){
            if (board[row][i]=='Q'){
                return false;
            }
        }
        for (int i=row-1,j=col-1;i>=0 && j>=0;i--,j--){
            if (board[i][j]=='Q'){
                return false;
            }

        }
        for (int i=row-1,j=col+1;i>=0&& j<=n-1;i--,j++){
            if (board[i][j]=='Q'){
                return false;
            }

        }
        return true;
    }
    void func(vector<vector<string>>&result,vector<string>&board,int n,int row){
        if (row==n){
            result.push_back(board);
        }
        for (int i=0;i<n;i++){
            if (is_valid(row,i, board,n)){
                board[row][i]='Q';
                func(result,board,n,row+1);
                board[row][i]='.';
            }
        }
    }
};