class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<int>s(arr.begin(),arr.end());
        int n=arr.size();
        int ans=0;
        for (int i=0;i<n;i++){
            for (int j=i+1;j<n;j++){
                int x=arr[i];
                int y=arr[j];
                int l=2;
                while(s.count(x+y)){
                    l++;
                    int z=x+y;
                    x=y;
                    y=z;
                }
                ans=max(ans,l);
            }
        }
        return ans>2 ?ans : 0;




        
    }
};