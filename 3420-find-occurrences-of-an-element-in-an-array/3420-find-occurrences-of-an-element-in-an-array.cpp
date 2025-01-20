class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int count=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                count++;
                mp[count]=i;

            }
        }
        int n=queries.size();
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            if(mp.find(queries[i]) !=mp.end()){
                ans[i]=mp[queries[i]];
            }
        }
        return ans;

        


    }
};