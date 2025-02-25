class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int ans = 0;
        stack<char> st;
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {  // Case when it's a closing bracket
                if (st.empty()) {
                    // If no matching opening bracket, we need an insertion
                    ans++;
                    if (i + 1 < n && s[i + 1] == ')') {
                        // We have a pair, so skip the next ')'
                        i++;
                    } else {
                        // We need one more closing bracket to balance
                        ans++;
                    }
                } else {
                    // Stack has an opening bracket to match
                    st.pop();  // Pop the matching '('
                    if (i + 1 < n && s[i + 1] == ')') {
                        // We have a valid '))', so skip the next ')'
                        i++;
                    } else {
                        // We need one more closing bracket to balance
                        ans++;
                    }
                }
            }
        }
        
        // If there are unmatched opening brackets remaining in the stack
        while (!st.empty()) {
            st.pop();
            ans += 2;  // Each '(' needs two closing brackets
        }
        
        return ans;
    }
};
