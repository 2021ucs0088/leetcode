class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string maxno="";
        for(int i=0;i<=n-3;i++){
            string s=num.substr(i,3);
            if(allsame(s)==true){
                maxno=max(maxno,s);
            }


        }
        
        return maxno;

    }
    bool allsame(string s){
        map<char,int>mp;
        for(char c:s){
            mp[c]++;
        }
        if(mp.size()==1){
            return true;
        }
        return false;
    }
};