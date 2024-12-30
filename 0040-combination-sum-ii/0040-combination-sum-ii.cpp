#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());  // Sort candidates to handle duplicates
        vector<vector<int>> result;
        vector<int> path;
        func(result, path, candidates, target, 0);
        return result;
    }

private:
    void func(vector<vector<int>>& result, vector<int>& path, vector<int>& candidates, int target, int start) {
        int csum = accumulate(path.begin(), path.end(), 0); 

        if (csum == target && find(result.begin(), result.end(), path) == result.end()) {
            result.push_back(path);
            return;
        }

        if (csum > target) {
            return;
        }

        for (int i = start; i < candidates.size(); i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;  // Skip duplicates

            path.push_back(candidates[i]);
            func(result, path, candidates, target, i + 1);
            path.pop_back();
        }
    }
};
