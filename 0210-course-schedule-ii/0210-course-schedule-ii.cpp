class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,vector<int>>mp;
        vector<int>indegree(numCourses);
        for(auto ele:prerequisites){
            mp[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int ele=q.front();q.pop();
            ans.push_back(ele);
            for(auto ngh:mp[ele]){
                if(--indegree[ngh]==0){
                    q.push(ngh);
                    
                }
            }
        }
        return ans;
        
    }
};