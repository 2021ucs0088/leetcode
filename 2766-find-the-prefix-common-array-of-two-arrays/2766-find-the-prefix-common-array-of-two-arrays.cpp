class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        map<int,int>mp;
        vector<int>C(n);

        for(int i=0;i<n;i++){
            mp[A[i]]++;
            mp[B[i]]++;
            for(auto [ele,f]:mp){
                if(f>1){
                    C[i]++;
                }
            }
            


        }
        return C;
    }
};