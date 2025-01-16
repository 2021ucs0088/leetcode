class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r=heights.size();
        int c=heights[0].size();
        vector<vector<int>>result(r,vector<int>(c,INT_MAX));
        result[0][0]=0;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,0,0});
        vector<vector<int>>dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(!pq.empty()){
            int diff=pq.top()[0];
            int i=pq.top()[1];
            int j=pq.top()[2];
            pq.pop();
            for(auto d:dir){
                int newx=i+d[0];
                int newy=j+d[1];
                if(newx>=0 && newy>=0 && newx<r && newy<c ){
                    int newdiff=max(diff,abs(heights[newx][newy]-heights[i][j]));
                    if(newdiff<result[newx][newy]){
                        result[newx][newy]=newdiff;
                        pq.push({newdiff,newx,newy});
                    }
                }
            }

        }
        return result[r-1][c-1];
    }
};