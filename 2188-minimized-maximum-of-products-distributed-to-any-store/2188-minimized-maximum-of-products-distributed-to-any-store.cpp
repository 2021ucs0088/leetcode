class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        long long left=1;
        long long right=1e5;
        long long ans=right;
        while(left<=right){
            long long mid=left+(right-left)/2;
            if(func(quantities,n,mid)){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }

        }
        return ans;

    }
    bool func(vector<int>& quantities ,int n ,long long mid){
        int count=0;
        for(int i=0;i<quantities.size();i++){
            count+=(quantities[i]+mid-1)/mid;

        }
        return count<=n;
    }

};