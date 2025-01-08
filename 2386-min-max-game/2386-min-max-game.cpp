class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        vector<int> vec(n / 2);
        for (int i = 0; i < n / 2; i++) {
            if(i%2==0){
                vec[i]=min(nums[i*2],nums[2*i+1]);
            }
            else{
                vec[i]=max(nums[i*2],nums[2*i+1]);
                

            }
        }
        return minMaxGame(vec);
    }
};