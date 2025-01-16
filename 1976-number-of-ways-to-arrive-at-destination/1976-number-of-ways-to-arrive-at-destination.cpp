class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> mp(n);
        int mod = 1e9 + 7;

        for (int i = 0; i < roads.size(); i++) {
            mp[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            mp[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> dis(n, LLONG_MAX); 
        vector<int> count(n, 0);
        dis[0] = 0;
        count[0] = 1;

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long t = pq.top().first;
            int currentnode = pq.top().second;
            pq.pop();

            if (t > dis[currentnode]) continue;

            for (auto ele : mp[currentnode]) {
                int nextnode = ele.first;
                int time = ele.second;

                if (dis[nextnode] > dis[currentnode] + time) {
                    dis[nextnode] = dis[currentnode] + time;
                    pq.push({dis[nextnode], nextnode});
                    count[nextnode] = count[currentnode]; 
                } else if (dis[nextnode] == dis[currentnode] + time) {
                    count[nextnode] = (count[nextnode] + count[currentnode]) % mod; 
                }
            }
        }

        return count[n - 1];
    }
};
