class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int> path;
        func(0, path, result, graph);
        return result;
    }
    void func(int start, vector<int>& path, vector<vector<int>>& result,
              vector<vector<int>>& graph) {
        path.push_back(start);
        if (start == graph.size() - 1) {
            result.push_back(path);
        } else {

            for (int ele : graph[start]) {
                func(ele, path, result, graph);
            }
        }
        path.pop_back();
    }
};