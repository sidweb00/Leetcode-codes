class Solution {
public:
    
    int dp[20];
    
    int rec(int x){
        if(x<=1)return 1;
        
        if(dp[x])return dp[x];
        int ans =0;
        for(int i=0;i<x;i++){
            ans+=rec(i)*rec(x-i-1);
        }
        return dp[x]=ans;
    }
    
    
    int numTrees(int n) {
        return rec(n);
    }
};