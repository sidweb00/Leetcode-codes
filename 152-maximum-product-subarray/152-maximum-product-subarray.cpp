class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int n=nums.size();
        
        int ans=-1e9;
        
        for(int i=0;i<n;i++){
            ans=max(ans,nums[i]);
        }
        
        int maxi=1,mini=1;
        
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                maxi=1;
                mini=1;
            }
            
            int m=max({nums[i],maxi*nums[i],mini*nums[i]});
            mini=min({nums[i],maxi*nums[i],mini*nums[i]});
            
            maxi=m;
            
            ans=max(ans,maxi);
        }
        
        return ans;
    }
};