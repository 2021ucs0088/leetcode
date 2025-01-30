class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool>vis(n,false);
        queue<int>q;
        q.push(0);
        vis[0]=true;
        while(!q.empty()){
            int current=q.front();
            q.pop();
            vis[current]=true;
            for(auto ele:rooms[current]){
                
                if(vis[ele]==false){
                    vis[ele]=true;
                    q.push(ele);

                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                return false;
            }
        }
        return true;
    }
};