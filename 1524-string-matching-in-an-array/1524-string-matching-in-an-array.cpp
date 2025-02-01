class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string>result;
        int n=words.size();
        set<string>s;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((words[j].find(words[i]) !=string::npos) && (i!=j)){
                    
                    s.insert(words[i]);
                    
                    
                }
                
            }
        }
        for(string ss:s){
            result.push_back(ss);
        }
        return result;
    }
};