class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curm=0;
        int global=-1e9;
        
        for(auto v:nums){
            curm=max(v,curm+v);
            global=max(global,curm);
        }
        return global;
    }
};