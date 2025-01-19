class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                char t=st.top();
                if(c==')' && t=='('){
                    st.pop();
                }
                else if(c=='}' && t=='{'){
                    st.pop();
                }
                else if(c==']' && t=='['){
                    st.pop();
                }
                else{
                    st.push(c);
                }


            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};