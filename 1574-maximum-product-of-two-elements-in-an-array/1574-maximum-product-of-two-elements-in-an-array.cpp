class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int,vector<int>,less<int>>pq;
        for (int num:nums){
            pq.push(num);
        }
        int ans=1;
        for (int i=0;i<2;i++){
            ans=ans*(pq.top()-1);
            pq.pop();

        }
        return ans;
        
    }
};