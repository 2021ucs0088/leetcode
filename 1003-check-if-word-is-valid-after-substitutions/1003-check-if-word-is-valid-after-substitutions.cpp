class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(st.size()<2){
                st.push(c);

            }
            else{
                int t1=st.top();
                st.pop();
                int t2=st.top();
                st.pop();
                if(c=='c' && t1=='b' && t2=='a' ){
                    continue;
                }
                else{
                    st.push(t2);
                    st.push(t1);
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