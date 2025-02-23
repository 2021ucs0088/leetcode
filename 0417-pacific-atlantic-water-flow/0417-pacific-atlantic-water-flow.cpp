class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        set<pair<int,int>>p;
        set<pair<int,int>>a;
        queue<pair<int,int>>q1;
        queue<pair<int,int>>q2;
        for(int i=0;i<r;i++){
            p.insert({i,0});
            q1.push({i,0});
        }
        for(int i=0;i<c;i++){
            p.insert({0,i});
            q1.push({0,i});
        }
        for(int i=0;i<r;i++){
            a.insert({i,c-1});
            q2.push({i,c-1});
        }
        for(int i=0;i<c;i++){
            a.insert({r-1,i});
            q2.push({r-1,i});
        }
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        
        while(!q1.empty()){
            int x=q1.front().first;
            int y=q1.front().second;
            q1.pop();
            for(auto d:dir){
                int newx=x+d[0];
                int newy=y+d[1];
                if(newx>=0 && newy>=0 && newx<r && newy<c && p.find({newx,newy}) ==p.end() && heights[newx][newy]>=heights[x][y]){
                    p.insert({newx,newy});
                    q1.push({newx,newy});
                }
            }

        }
        while(!q2.empty()){
            int x=q2.front().first;
            int y=q2.front().second;
            q2.pop();
            for(auto d:dir){
                int newx=x+d[0];
                int newy=y+d[1];
                if(newx>=0 && newy>=0 && newx<r && newy<c && a.find({newx,newy}) ==a.end() && heights[newx][newy]>=heights[x][y]){
                    a.insert({newx,newy});
                    q2.push({newx,newy});
                }
            }

        }
        vector<vector<int>>result;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(p.count({i,j}) && a.count({i,j})){
                    result.push_back({i,j});
                }
            }
        }
        return result;



    }
};