class Solution {
public:
    
    int dp[102][102][102];
    vector<int>a;
    
    int rec(int l,int r,int k){
        if(l>r)return 0;
        
        if(dp[l][r][k]==-1){
            int ans =(k+1)*(k+1)+rec(l+1,r,0);
            
            for(int i=l+1;i<=r;i++){
                if(a[i]==a[l]){
                    ans=max(ans,rec(l+1,i-1,0)+rec(i,r,k+1));
                }
            }
            dp[l][r][k]=ans;
        }
        
        return dp[l][r][k];
    }
    
    
    int removeBoxes(vector<int>& boxes) {
        a=boxes;
            
        memset(dp,-1,sizeof(dp));
        
        return rec(0,boxes.size()-1,0);
    }
};