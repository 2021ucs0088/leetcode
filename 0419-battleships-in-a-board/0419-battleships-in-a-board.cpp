class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count=0;
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int val=board[i][j];
                if(val=='.'){
                    continue;

                }
                char left='0';
                char up='0';
                if(j-1>=0){
                    left=board[i][j-1];
                }
                if(i-1>=0 ){
                    up=board[i-1][j];
                }
                if(j-1<0 || left =='.'){
                    if(i-1<0 || up=='.'){
                        count++;
                    }
                }
            }
        }
        return count;
    }
};