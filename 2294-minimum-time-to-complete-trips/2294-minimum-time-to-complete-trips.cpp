class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long start=0;
        long long end=1e14;
        long long ans=end;
        while(start<=end){
            long long mid=start+(end-start)/2;
            if(func(time,totalTrips,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
    bool func(vector<int>& time,int totalTrips ,long long mid){
        long long trip=0;
        for(int t:time){
            trip+=(mid/t);
        }
        return (trip>=totalTrips);
    }
};