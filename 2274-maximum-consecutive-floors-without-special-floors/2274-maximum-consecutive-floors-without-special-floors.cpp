class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        int maxval=0;
        for(int i=1;i<special.size();i++){
            maxval=max(maxval,special[i]-special[i-1]-1);

        }
        maxval=max(maxval,special[0]-bottom);
        maxval=max(maxval,top-special[special.size()-1]);
        return maxval;
    }
};