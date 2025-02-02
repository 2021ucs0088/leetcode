class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count=0;
        int n=words.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i !=j && i<j){
                    if(isPrefixAndSuffix(words[i],words[j])){
                        count++;
                    }
                }
            }
        }
        return count;
    }
    bool isPrefixAndSuffix (string str1,string str2){
        if(str1.size()>str2.size()){
            return false;
        }
        int n1=str1.size();
        int n2=str2.size();
        if(str2.substr(0,n1) !=str1){
            return false;
        }
        if(str2.substr(n2-n1) !=str1){
            return false;
        }
        return true;
        
        
    }
};