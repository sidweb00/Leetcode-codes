class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        vector<vector<int>>dp(m,vector<int>(n,0));
        
        if(obstacleGrid[0][0] || obstacleGrid[m-1][n-1])return 0;
        
        int flag=0;
        dp[0][0]=1;
        for(int i=1;i<m;i++){
            if(obstacleGrid[i][0])flag=1;
            if(flag){
                dp[i][0]=0;
            }
            else dp[i][0]=1;
        }
        flag=0;
        for(int i=1;i<n;i++){
            if(obstacleGrid[0][i])flag=1;
            if(flag){
                dp[0][i]=0;
            }
            else dp[0][i]=1;
        }
        
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
               
                if(obstacleGrid[i][j])continue;
                
                if(obstacleGrid[i-1][j]!=1)dp[i][j]+=dp[i-1][j];
                if(obstacleGrid[i][j-1]!=1)dp[i][j]+=dp[i][j-1];
            }
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"\n";
        return dp[m-1][n-1];
    }
};