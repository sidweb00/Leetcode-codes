class Solution {
public:
    
    int dp[1001][1001];
    string s1,s2;
    
    int rec(int i,int j){
        
        // base and prune 
        if(i==0 && j==0){
            if(s1[i]==s2[j])return dp[i][j]=1;
            return dp[i][j]=0;
        }
        if(i<0||j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j])return dp[i][j]=rec(i-1,j-1)+1;
        return dp[i][j]=max(rec(i-1,j),rec(i,j-1));
        
    }
    
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        s1=text1;s2=text2;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j]=-1;
            }
        }
        
//         if(text1[0]==text2[0])dp[0][0]=1;
//         else dp[0][0]=0;
        
//         for(int i=1;i<n;i++){
//             for(int j=1;j<m;j++){
//                 if(s1[i]==s2[j])dp[i][j]=dp[i-1][j-1]+1;
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
        
        return rec(n-1,m-1);
        
    }
};