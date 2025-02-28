class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double,vector<double>,less<double>>pq(nums.begin(),nums.end());
        double total=0;
        for(int num:nums){
            total+=num;
        }
        total=total/2.0;
        int count=0;
        while(!pq.empty() && total>0){
            double top=pq.top();
            pq.pop();
            pq.push(top/2.0);
            total-=top/2.0;
            count++;
        }
        return count;

    }
};