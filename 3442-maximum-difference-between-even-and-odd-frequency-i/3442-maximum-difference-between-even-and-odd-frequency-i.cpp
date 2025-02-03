class Solution {
public:
    int maxDifference(string s) {
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        vector<int>even;
        vector<int>odd;
        for(auto [c,f]:mp){
            if(f%2==0){
                even.push_back(f);
            }
            else{
                odd.push_back(f);
            }
        }
        int evenmax= *max_element(even.begin(),even.end());
        int evenmin= *min_element(even.begin(),even.end());
        int oddmax= *max_element(odd.begin(),odd.end());
        int oddmin= *min_element(odd.begin(),odd.end());
        return max({evenmax-oddmin,oddmax-evenmin});

    }
};