class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     
        unordered_map<int,int>mp;
        int i=0;
        for(auto v:nums){
            int x=target-v;
            if(mp.find(x)!=mp.end()){
                return {i,mp[x]};
            }
            mp[v]=i;
            i++;
        }
        return {};
    }
};