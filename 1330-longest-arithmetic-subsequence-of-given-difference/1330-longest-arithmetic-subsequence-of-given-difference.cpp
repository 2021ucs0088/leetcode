class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        unordered_map<int,int>mp;
        int longest=0;
        for (int num:arr){
            mp[num]=mp[num-difference]+1;
            longest=max(longest,mp[num]);


        }
        return longest;
    }
};