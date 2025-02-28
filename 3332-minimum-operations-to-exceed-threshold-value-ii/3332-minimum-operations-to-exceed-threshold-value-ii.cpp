class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>,greater<long long>>pq(nums.begin(),nums.end());
        int count=0;
        while(pq.top()<k && pq.size()>1){
            long long first=pq.top();
            pq.pop();
            long long second=pq.top();
            pq.pop();
            long long x=min(first,second)*2+max(first,second);
            pq.push(x);
            count++;


        }
        return count;

    }
};