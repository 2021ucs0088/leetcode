class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        map<int, vector<int>> mp;
        
        for (auto ele : prerequisites) {
            mp[ele[0]].push_back(ele[1]);
        }
        vector<bool> result(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            vector<bool> vis(numCourses);
            result[i] = func(queries[i][0], queries[i][1], mp, vis);
        }
        return result;
    }
    bool func(int i, int j, map<int, vector<int>>& mp, vector<bool>& vis) {
        if (i == j) {
            return true;
        }
        vis[i] = true;
        for (auto ele : mp[i]) {
            if (vis[ele] == false) {
                if(func(ele, j, mp, vis)){
                    return true;
                }
            }
        }
        return false;
    }
};