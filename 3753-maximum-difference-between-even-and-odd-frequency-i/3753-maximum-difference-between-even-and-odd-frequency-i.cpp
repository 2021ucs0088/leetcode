class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        int oddmax=0;
        int evenmin=INT_MAX;
        for(auto [c,f]:mp){
            if(f%2==0){
                evenmin=min(evenmin,f);

            }
            else{
                oddmax=max(oddmax,f);
            }

        }
        return oddmax-evenmin;
    }
};