class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r=0;
        for(int ele:nums){
            r=r^ele;
        }
        return r;
    }
    
};