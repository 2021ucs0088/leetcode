class Solution {
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<int>child(k,0);
        int result=INT_MAX;
        func(cookies,0,child,result,k);
        return result;
    }
    void func(vector<int>& cookies,int idx,vector<int>&child,int &result,int &k){
        if(idx>=cookies.size()){
            int unfair=*max_element(child.begin(),child.end());
            result=min(result,unfair);
            return ;
        }
        for(int i=0;i<k;i++){
            child[i]+=cookies[idx];
            func(cookies,idx+1,child,result,k);
            child[i]-=cookies[idx];
        }
    }
};