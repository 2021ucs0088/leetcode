class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int>result;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<arr.size();i++){
            int d=abs(arr[i]-x);
            pq.push({d,arr[i]});

        }
        for(int i=0;i<k;i++){
            int d=pq.top().first;
            int ele=pq.top().second;
            pq.pop();
            result.push_back(ele);
        }
        sort(result.begin(),result.end());
        return result;
    }
};