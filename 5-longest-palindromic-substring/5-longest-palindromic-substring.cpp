class Solution {
public:
    string longestPalindrome(string s) {
        
        int n=s.length();
        
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        // len=1
        
        for(int i=0;i<n;i++){
            dp[i][i]=1;
        }
        
        // len=2
        
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])dp[i][i+1]=1;
        }
        
        // len>=3
        
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(dp[i+1][j-1] && s[i]==s[j]){
                    dp[i][j]=1;
                }
            }
        }
        
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(dp[i][j]){
                    int len=j-i+1;
                    if(len>maxlen){
                        maxlen=len;
                        // ans=s.substr(i,len);
                        start=i;
                    }
                }
            }
        }
        
        return s.substr(start,maxlen);
    }
};