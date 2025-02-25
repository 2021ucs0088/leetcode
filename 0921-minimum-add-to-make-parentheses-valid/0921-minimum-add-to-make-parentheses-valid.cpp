class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char>st;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                char top=st.top();
                if(top=='(' && c==')'){
                    st.pop();

                }
                else{
                    st.push(c);
                }

            }
        }
        return st.size();
    }
};