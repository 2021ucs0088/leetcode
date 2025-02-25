class Solution {
public:
    int minSwaps(string s) {
        int count=0;
        stack<char>st;
        for(char c:s){
            if(st.empty()){
                st.push(c);
            }
            else{
                char top=st.top();
                if(top=='[' && c==']'){
                    st.pop();
                }
                else{
                    st.push(c);
                }
            }
        }
        while(!st.empty()){
            if(st.top()=='['){
                count++;
            }
            st.pop();
        }
        return (count+1)/2;
    }
};