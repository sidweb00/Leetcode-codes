class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int>sols;
        
        for(auto v:nums){
            if(sols.empty()|| v>sols.back()){
                sols.push_back(v);
            }
            else{
                auto it=std::lower_bound(sols.begin(),sols.end(),v);
                *it=v;
            }
        }
        return sols.size();
    }
};