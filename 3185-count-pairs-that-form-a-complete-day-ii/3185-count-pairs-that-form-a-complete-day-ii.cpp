class Solution {
public:
    long long countCompleteDayPairs(vector<int>& hours) {
        unordered_map<int,int>mp;
        long long count=0;
        for(int num:hours){
            int current=num%24;
            int complement=(24-(num%24))%24;
            if (mp.find(complement) !=mp.end()){
                count+=mp[complement];
                mp[current]++;

            }
            else{
                mp[current]++;
            }
        }
        return count;

    }
};