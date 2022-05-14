class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxend=0;
        int globalm=-1e9;
        
        for(int i=0;i<n;i++){
            maxend+=nums[i];
            if(maxend<=nums[i])maxend=nums[i];
            globalm=max(globalm,maxend);
        }
        return globalm;
    }
};