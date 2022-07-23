class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a=0,b=0,c=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)a++;
            else if(nums[i]==1)b++;
            else c++;
        }
        int i=0;
        while(a--){
            nums[i]=0;
            i++;
        }
        while(b--){
            nums[i]=1;
            i++;
        }
        while(c--){
            nums[i]=2;
            i++;
        }
    }
};