class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        stack<char>st;
        vector<int>freq(26);
        set<char>seen;
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<n;i++){
            freq[s[i]-'a']--;
            if(st.empty()){
                if(seen.find(s[i])==seen.end()){
                    st.push(s[i]);
                    seen.insert(s[i]);
                }

            }else{
                if(seen.find(s[i])==seen.end()){
                    while(!st.empty() && st.top()>s[i] && freq[st.top()-'a']>0){
                        seen.erase(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                    seen.insert(s[i]);
                }

            }

        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
};