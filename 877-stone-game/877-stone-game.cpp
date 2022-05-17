class Solution {
public:
    
    int dp[550][550];
    vector<int>a;
    
    int rec(int l,int r){
        if(l>=r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        return dp[l][r]=max(a[l]-rec(l+1,r),a[r]-rec(l,r-1));
    }
    
    bool stoneGame(vector<int>& piles) {
        a=piles;
        int n=piles.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        
        if(rec(0,n-1)>0)return 1;
        return 0;
    }
};