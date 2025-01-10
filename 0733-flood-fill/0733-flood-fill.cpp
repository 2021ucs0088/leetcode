class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        int r=image.size();
        int c=image[0].size();
        int originalcolor=image[sr][sc];
        if (originalcolor == color) {
            return image;
        }
        queue<pair<int,int>>q;
        image[sr][sc]=color;
        q.push({sr,sc});
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto d:dir){
                int newx=x+d[0];
                int newy=y+d[1];
                if(newx>=0 && newy>=0 && newx<r && newy<c && image[newx][newy]==originalcolor){
                    image[newx][newy]=color;
                    q.push({newx,newy});
                }
            }
        }
        return image;
    }
};