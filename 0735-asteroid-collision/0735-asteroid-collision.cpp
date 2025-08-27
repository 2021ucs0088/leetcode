class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            if (st.empty()) {
                st.push(asteroids[i]);
            } else {
                if (st.top() > 0) {
                    if (asteroids[i] > 0) {
                        st.push(asteroids[i]);
                    } else {
                        if (st.top() == abs(asteroids[i])) {
                            st.pop();
                        } else if (st.top() > abs(asteroids[i])) {
                            continue;
                        }
                        else {
                            int temp=asteroids[i];
                            while (!st.empty() && st.top()>0 && st.top() < abs(temp) ) {
                                st.pop();
                            }
                            if(st.empty() || st.top()<0){
                                st.push(asteroids[i]);
                            }
                            else if(st.top()== abs(temp)){
                                st.pop();
                            }
                        }
                    }

                } else {
                    st.push(asteroids[i]);
                }
            }
        }
        vector<int> result;
        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};