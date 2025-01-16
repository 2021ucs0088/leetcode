class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double>prob(n,0);
        prob[start_node]=1.0;
        map<int,vector<pair<int,double>>>mp;
        for(int i=0;i<edges.size();i++){
            mp[edges[i][0]].push_back({edges[i][1],succProb[i] });
            mp[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>,vector<pair<double,int>>,less<pair<double,int>>>pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            int currentnode=pq.top().second;
            pq.pop();
            for(auto ele:mp[currentnode]){
                int nextnode=ele.first;
                double p=ele.second;
                if(prob[currentnode]*p>prob[nextnode]){
                    prob[nextnode]=prob[currentnode]*p;
                    pq.push({prob[nextnode],nextnode});

                }
            }
        }
        return prob[end_node];

    }
};