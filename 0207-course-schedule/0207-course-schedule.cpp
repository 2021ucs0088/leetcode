class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=prerequisites.size();
        unordered_map<int,vector<int>>mp;
        vector<int>indegree(numCourses);
        for(int i=0;i<n;i++){
            mp[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;

        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<bool>visited(numCourses,false);
        vector<int>result;
        while(!q.empty()){
            int ele=q.front();
            q.pop();
            visited[ele]=true;
            result.push_back(ele);
            for(int ngh:mp[ele]){
                if(--indegree[ngh]==0){
                    q.push(ngh);
                }
            }
        }
        return result.size()==numCourses;
    }
};