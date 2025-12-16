class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto ele=pq.top();
            pq.pop();
            int d=ele.first;
            int node=ele.second;
            for(auto ngh:mp[node]){
                int nextnode=ngh.first;
                int nextdist=ngh.second;
                if(d+nextdist<dist[nextnode]){
                    dist[nextnode]=d+nextdist;
                    pq.push({d+nextdist,nextnode});
                }



            }
        }
        int r= *max_element(dist.begin()+1,dist.end());
        return r==INT_MAX?-1:r;




    }
};