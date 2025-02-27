class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long start=1;
        long long end=1e5;
        long long ans=end;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if (func(quantities,mid,n)){
                ans=mid;
                end=mid-1;


            }
            else{
                start=mid+1;
            }


        }
        return ans;
        
    }
    bool func(vector<int>& quantities,long long mid,int n){
        int store=0;
        for (int i=0;i<quantities.size();i++){
            store+=(quantities[i]+mid-1)/mid;
        }
        return store<=n;
    }


};