class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long start=1;
        long long end=*max_element(candies.begin(),candies.end());
        long long ans=0;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(func(candies,k,mid)){
                ans=mid;
                start=mid+1;
            }
            else{
                end=mid-1;
            }

        }
        return ans;
    }
    bool func(vector<int>& candies,long long k ,long long mid){
        long long child=0;
        for(int i=0;i<candies.size();i++){
            child+=(candies[i])/mid;
        }
        return child>=k;
    }
};