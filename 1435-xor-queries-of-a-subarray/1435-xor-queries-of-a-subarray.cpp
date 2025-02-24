class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        vector<int>pf(n+1);
        for(int i=1;i<=n;i++){
            pf[i]=pf[i-1]^arr[i-1];
        }
        int m=queries.size();
        vector<int>result(m);
        for(int i=0;i<m;i++){
            int left=queries[i][0];
            int right=queries[i][1];
            result[i]=pf[right+1]^pf[left];

        }
        return result;


    }
};