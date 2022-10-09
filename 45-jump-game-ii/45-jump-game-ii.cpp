class Solution {
public:
    int jump(vector<int>& nums) {
     
        int n=nums.size();
        
        int l=0,r=0;
        int maxi=1;
        
        int ans =0;
        
        while(r<n-1){
            for(int i=l;i<r+1;i++){
                maxi=max(maxi,i+nums[i]);
            }
            
            l=r+1;
            r=maxi;
            ans++;
        }
        return ans;
              
    }
};