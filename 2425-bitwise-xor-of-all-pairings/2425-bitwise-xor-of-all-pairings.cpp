class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int r1=0;
        int r2=0;
        for(int i=0;i<nums2.size();i++){
            r2=r2^nums2[i];
        }
        for(int i=0;i<nums1.size();i++){
            r1=r1^nums1[i];
        }
        int result=0;
        for(int i=0;i<nums2.size();i++){
            result=result^r1;

        }
        for(int i=0;i<nums1.size();i++){
            result=result^r2;

        }
        return result;
    }
};