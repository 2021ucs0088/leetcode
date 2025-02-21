class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        map<int,map<int,int>>mymap;
        for (auto ele:pick){
            mymap[ele[0]][ele[1]]++;
        }
        int result=0;
        for (int i=0;i<n;i++){
            for (auto [a,b]:mymap[i]){
                if (b>i){
                    result++;
                    break;
                }
            }
        }
        return result;

        
    }
};