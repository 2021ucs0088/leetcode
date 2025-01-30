class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        map<int,vector<int>>mp;
        vector<int>indegree(n);
        for(auto ele:edges){
            mp[ele[0]].push_back(ele[1]);
            mp[ele[1]].push_back(ele[0]);
            indegree[ele[0]]++;
            indegree[ele[1]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i]==1){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int s=q.size();
            ans.clear();
            for(int i=0;i<s;i++){
                int ele=q.front();
                q.pop();
                ans.push_back(ele);
                indegree[ele]--;
                for(auto ngh:mp[ele]){
                    indegree[ngh]--;
                    if(indegree[ngh]==1){
                        q.push(ngh);
                    }
                }


            }
        }
        if(n==1){
            ans.push_back(0);
        }
        return ans;
    }
};