class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int, vector<int>> mp;
        vector<int>indegree(numCourses);
        for (auto ele : prerequisites) {
            mp[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int count = 0;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            count++;
            
            for (auto ngh : mp[current]) {
                if(--indegree[ngh]==0){
                    q.push(ngh);
                }
            }
        }
        if (count == numCourses) {
            return true;
        }
        return false;
    }
};