class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,less<int>>pq;
        for(int num:nums){
            pq.push(num);
        }
        int ans=0;
        for(int i=0;i<k;i++){
            int top=pq.top();
            ans+=top;
            pq.pop();
            pq.push(top+1);
        }
        return ans;
    }
};