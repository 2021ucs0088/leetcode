class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int>mp;
        int count=0;
        for(int num:time){
            int x=(60-(num%60))%60;
            if (mp.find(x) !=mp.end()){
                count+=mp[x];
                mp[num%60]++;
            }
            else{
                mp[num%60]++;

            }
        }
        return count;
    }
};