class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        for(int num:nums1){
            if(find(nums2.begin(),nums2.end(),num) !=nums2.end()){
                return num;
            }
        }
        int x=nums1[0];
        int y=nums2[0];
        if(x>y){
            return y*10+x;
        }
        else{
            return x*10+y;
        }
        return -1;


    }
};