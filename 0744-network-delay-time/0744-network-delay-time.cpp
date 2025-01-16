class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<times.size();i++){
            mp[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            int currentnode=pq.top().second;
            pq.pop();
            for(auto ele:mp[currentnode]){
                int d=ele.second;
                int nextnode=ele.first;
                if(dis[nextnode]>dis[currentnode]+d){
                    dis[nextnode]=dis[currentnode]+d;
                    pq.push({dis[nextnode],nextnode});
                }
            }

        }
        int maxno=*max_element(dis.begin()+1,dis.end());
        if(maxno==INT_MAX){
            return -1;
        }
        return maxno;
    }
};