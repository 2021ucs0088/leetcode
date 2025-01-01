class Solution {
public:
    int punishmentNumber(int n) {
        int count=0;
        for(int i=1;i<=n;i++){
            if(func(to_string(i*i),i)){
                count+=(i*i);
            }
        }
        return count;
        
    }
    int func(string s,int target){
        if(s=="" && target==0){
            return true;
        }
        for(int i=0;i<s.size();i++){
            string left=s.substr(0,i+1);
            int leftnum=stoi(left);
            if(leftnum>target){
                return false;
            }
            if(func(s.substr(i+1),target-leftnum)){
                return true;
            }
        }
        return false;
        

    }
};
