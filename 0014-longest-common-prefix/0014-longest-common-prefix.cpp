class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return ""; 

        string ans = "";
        int maxl = INT_MAX;
        for (const auto& ele : strs) {
            maxl = min(maxl, static_cast<int>(ele.size()));
        }
        for (int j = 0; j < maxl; j++) {
            char c = strs[0][j];
            bool valid = true;

            for (int i = 1; i < strs.size(); i++) {
                if (strs[i][j] != c) {
                    valid = false;
                    break; 
                }
            }

            if (valid) {
                ans += c; 
            } else {
                break; 
            }
        }

        return ans;
    }
};
