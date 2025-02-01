class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int>vec(n+1);
        for(auto ele:shifts){
            int start=ele[0];
            int end=ele[1];
            int dir=ele[2];
            if(dir==0){
                vec[start]--;
                vec[end+1]++;
            }
            else{
                vec[start]++;
                vec[end+1]--;
            }
        }
        int shift=0;
        for(int i=0;i<n;i++){
            shift+=vec[i];
            char newchar=((s[i]-'a'+(shift))%26+26)%26;
            s[i]=newchar+'a';

        }
        return s;

    }

};