class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        set<int>s;
        int n=arr.size();
        for (int i=0;i<n-1;i++){
            s.insert(arr[i]-arr[i+1]);

        }
        if(s.size()==1){
            return true;
        }
        return false;
    }
};