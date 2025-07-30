class Solution {
public:
    int smallestNumber(int n, int t) {
        for(int i=n;i<=100;i++){
            int p=product(i);
            if(p%t==0){
                return i;
                break;
            }
        }
        return -1;




        
    }
    int product(int n){
        int x=1;
        while(n){
            int r=n%10;
            n=n/10;
            x=x*r;
        }
        return x;
    }
};