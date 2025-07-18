class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<pair<int,int>>>pq;
        for(auto[x,f]:mp){
            pq.push({f,x});
        }
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }

};