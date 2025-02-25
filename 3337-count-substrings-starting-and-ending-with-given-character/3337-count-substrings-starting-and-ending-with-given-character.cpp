class Solution {
public:
    long long countSubstrings(string s, char c) {
        int count=0;
        for(char ch:s){
            if(ch==c){
                count++;
            }
        }
        long long  ans=0;
        ans=(static_cast<long long>(count)*(count+1))/2;
        return ans;
    }
};