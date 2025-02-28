class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums,
                                       vector<vector<int>>& queries) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            pq;
        for (int i = 0; i < nums.size(); i++) {
            pq.push({nums[i], i});
        }
        vector<bool> marked(nums.size(), false);
        vector<long long> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int idx = queries[i][0];
            int k = queries[i][1];
            if (marked[idx] == false) {
                marked[idx] = true;
            }
            int markedcount = 0;
            while (!pq.empty() && markedcount < k) {
                int top = pq.top().first;
                int index = pq.top().second;
                pq.pop();
                if (marked[index] == false) {
                    markedcount++;
                    marked[index] = true;
                }
            }
            for (int j = 0; j < nums.size(); j++) {
                if (marked[j] == false) {
                    result[i] += nums[j];
                }
            }
        }
        return result;
    }
};