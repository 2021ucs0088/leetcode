class Solution {
public:
    int minInsertions(string s) {
        stack<char> st;
        int n = s.size(), count = 0;

        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(s[i]);
            } else {
                char top = st.top();
                if (top == '(' && s[i] == ')') {
                    if (i + 1 < n && s[i + 1] == ')') {
                        st.pop();
                        i++; 
                    } else {
                        count++; 
                        st.pop();
                    }
                } else {
                    st.push(s[i]);
                }
            }
        }

        while (!st.empty()) {
            char first = st.top();
            st.pop();
            if (!st.empty()) {
                char second = st.top();
                st.pop();

                if (first == '(') {
                    count += 2;
                    st.push(second);
                } else if (first == ')' && second == ')') {
                    count++;
                } else if (first == ')' && second == '(') {
                    count += 2;
                }
            } else {
                count += (first == '(') ? 2 : 1;
            }
        }

        return count;
    }
};
