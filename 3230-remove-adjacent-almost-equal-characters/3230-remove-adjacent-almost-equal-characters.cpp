class Solution {
public:
    int removeAlmostEqualCharacters(string word) {
        int n=word.size();
        int count=0;
        for(int i=1;i<n;i++){
            if(word[i-1]==word[i] || abs(word[i]-word[i-1])==1){

                count++;
                i=i+1;
            }

        }
        return count;
    }
};