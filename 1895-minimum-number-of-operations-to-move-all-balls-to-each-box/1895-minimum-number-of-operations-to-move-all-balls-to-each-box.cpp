class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pf(n+1);
        for(int i=1;i<=n;i++){
            pf[i]=pf[i-1]+1;
        }
        vector<int>oneindex;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                oneindex.push_back(i);

            }
            

        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            for(int idx:oneindex){
                ans[i]+=abs(pf[idx]-pf[i]);
            }
        }
        return ans;
        
        
    }
    
};