class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;
        for(int num:nums){
            vector<int>level;
            while(num>0){
                int r=num%10;
                num=num/10;
                level.push_back(r);

            }
            reverse(level.begin(),level.end());
            for(auto ele:level){
                ans.push_back(ele);
            }
        }
        return ans;
    }

};