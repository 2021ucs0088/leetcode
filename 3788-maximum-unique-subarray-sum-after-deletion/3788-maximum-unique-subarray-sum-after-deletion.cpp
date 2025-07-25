class Solution {
public:
    int maxSum(vector<int>& nums) {
        map<int,int>mp;
        for(int num:nums){
            mp[num]=1;
        }
        priority_queue<int,vector<int>,less<int>>pq;
        for(auto[x,f]:mp){
            pq.push(x);
        }
        int result=0;
        if(pq.top()<=0){
            return pq.top();
        }
        else{
            while(pq.top()>0 && !pq.empty()){
                result+=pq.top();
                pq.pop();
            }
        }
        return result;
        
    }
};