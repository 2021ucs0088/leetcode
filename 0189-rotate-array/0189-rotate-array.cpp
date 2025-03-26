class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        auto l=nums;
        int n=nums.size();
        k=k%n;
        for(int i=0;i<n-k;i++){
            nums[i+k]=l[i];
        }
        for (int i=n-k;i<n;i++){
            nums[i-n+k]=l[i];
        }
        
    }
};