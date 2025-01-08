class Solution {
public:
vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
    bool exist(vector<vector<char>>& board, string word) {
        int row=board.size();
        int col=board[0].size();
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]==word[0]){
                    vector<vector<bool>>vis(row,vector<bool>(col,false));
                    if(func(board,i,j,word,0,vis)){
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
    bool func(vector<vector<char>>& board,int i,int j,string &word,int idx,vector<vector<bool>>&vis){
        int m=board.size();
        int n=board[0].size();
        if(idx==word.size()){
            return true;
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j] !=word[idx] || vis[i][j]==true){
            return false;
        }
        vis[i][j]=true;
        for(auto d:dir){
            if(func(board,i+d[0],j+d[1],word,idx+1,vis)){
                return true;
            }

        }
        vis[i][j]=false;
        return false;

        
    }
};