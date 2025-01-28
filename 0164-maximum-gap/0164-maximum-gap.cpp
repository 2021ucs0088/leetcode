class Solution {
public:
    int maximumGap(vector<int>& nums) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int num:nums){
            pq.push(num);
        }
        if(nums.size()<2){
            return 0;
        }
        int maxval=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            int x=pq.top();
            pq.pop();
            maxval=max(maxval,abs(x-pq.top()));

        }
        return maxval;
    }
};