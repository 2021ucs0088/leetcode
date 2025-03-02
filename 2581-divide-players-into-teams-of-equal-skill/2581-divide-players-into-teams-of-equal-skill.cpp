class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n=skill.size();
        sort(skill.begin(),skill.end());
        int left=0;
        int right=n-1;
        int total=0;
        for(int num:skill){
            total+=num;
        }
        if(total*2%n !=0){
            return -1;
        }
        int target=total*2/n;
        long long ans=0;
        while(left<right){
            if(skill[left]+skill[right] !=target){
                return -1;
            }
            else{
                ans+=(skill[left]*skill[right]);
                left++;
                right--;
            }
        }
        return ans;


    }
};