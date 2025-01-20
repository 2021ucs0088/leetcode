class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        map<int,pair<int,int>>mp;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mp[mat[i][j]]={i,j};
            }
        }
        vector<int>v1(r);
        vector<int>v2(c);
        for(int i=0;i<arr.size();i++){
            auto [row,col]=mp[arr[i]];
            v2[col]++;
            v1[row]++;
            if(v2[col]==r || v1[row]==c){
                return i;
            }
        }
        return -1;

    }
    
    
};