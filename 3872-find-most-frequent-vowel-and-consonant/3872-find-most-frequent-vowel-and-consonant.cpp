class Solution {
public:
    int maxFreqSum(string s) {
        map<char ,int>vowel;
        map<char ,int>consonant ;
        for(char c:s){
            if(func(c)){
                vowel[c]++;
            }
            else{
                consonant[c]++;

            }
        }
        int max1=0;
        int max2=0;
        for(auto [c,f]:vowel){
            max1=max(max1,f);
        }
        for(auto [c,f]:consonant){
            max2=max(max2,f);
        }
        return max1+max2;

        
    }
    bool func(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u'){
            return true;
        }
        return false;
    }
};