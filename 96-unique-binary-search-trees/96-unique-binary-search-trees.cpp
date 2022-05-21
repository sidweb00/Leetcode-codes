class Solution {
public:
    
    int catalan(int n,vector<int>&dp){
        if(dp[n])return dp[n];
        int ans =0;
        for(int i=0;i<n;i++){
            ans+=catalan(i,dp)*catalan(n-i-1,dp);
        }
       dp[n] = ans; 
        return ans;
    }
    
    int numTrees(int n) {
        vector<int>dp(n+1);
        dp[0]=dp[1]=1;
        return catalan(n,dp);
    }
};