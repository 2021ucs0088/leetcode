class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long start=1;
        long long end=end = *max_element(piles.begin(), piles.end());
        long long ans=end;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(func(piles,h,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    bool func(vector<int>& piles,int h,long long mid){
        long long  hour=0;
        for(int i=0;i<piles.size();i++){
            hour+=(piles[i]+mid-1)/mid;
        }
        return hour<=h;
    }
};