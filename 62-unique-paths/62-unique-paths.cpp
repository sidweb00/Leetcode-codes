class Solution {
public:
    
    int dp[110][110];
    int M,N;
    int rec(int i,int j){
        if(i==M-1 && j==N-1){
            return 1;
        }
        
        if(i>=M || j>=N)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        dp[i][j]=rec(i+1,j)+rec(i,j+1);
        return dp[i][j];
    }
    
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        M=m;N=n;
        return rec(0,0);
    }
};