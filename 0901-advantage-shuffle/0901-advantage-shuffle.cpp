class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int>result(n);
        multiset<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums1[i]);
        }
        for(int i=0;i<n;i++){
            auto it=s.upper_bound(nums2[i]);
            if(it !=s.end()){
                result[i]=(*it);
                s.erase(it);
            }
            else{
                result[i]=(*(s.begin()));
                s.erase(s.begin());


            }
            
        }
        return result;
    }
};