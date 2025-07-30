class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        int maxno = 0;
        for (auto [x, f] : mp) {
            maxno = max(maxno, f);
        }
        vector<bool> prime(maxno + 1, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i*i < maxno + 1; i++) {
            if (prime[i]) {
                for (int j = i*i; j <= maxno; j+=i) {
                    if (j % i == 0) {
                        prime[j] = false;
                    }
                }
            }
        }
        for(auto [x,f]:mp){
            if(prime[f]==true){
                return true;
                break;
            }
        }
        return false;
    }
};