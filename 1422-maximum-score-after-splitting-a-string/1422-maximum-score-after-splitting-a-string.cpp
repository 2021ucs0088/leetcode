class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        int maxans=INT_MIN;
        for(int i=1;i<n;i++){
            string left=s.substr(0,i);
            string right=s.substr(i);
            int l=noofzero(left);
            int r=noofone(right);
            maxans=max(maxans,l+r);

        }
        return maxans;
    }
    int noofzero(string s){
        int count=0;
        for(char c:s){
            if(c-'0'==0){
                count++;

            }
        }
        return count;

    }
    int noofone(string s){
        int count=0;
        for(char c:s){
            if(c-'0'==1){
                count++;

            }
        }
        return count;

    }
};