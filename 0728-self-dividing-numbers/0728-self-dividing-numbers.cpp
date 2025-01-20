class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int>ans;
        for(int i=left;i<=right;i++){
            if(func(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
    bool func(int x){
        int n=x;
        while(n){
            int d=n%10;
            if(d==0 || x%d !=0){
                return false;
            }
            n=n/10;

        }
        return true;
    }
};
