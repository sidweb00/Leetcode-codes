class Solution {
public:
    int trap(vector<int>& height) {
        
        int n=height.size();
        
        int pre[n+1];
        int suf[n+1];
        
        pre[0]=0;suf[n-1]=0;
        
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],height[i-1]);
        }
        
        for(int i=n-2;i>=0;i--){
            suf[i]=max(suf[i+1],height[i+1]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(min(pre[i],suf[i])>height[i]){
                ans+=min(pre[i],suf[i])-height[i];
            }
        }
    
        return ans;
    }
    
};