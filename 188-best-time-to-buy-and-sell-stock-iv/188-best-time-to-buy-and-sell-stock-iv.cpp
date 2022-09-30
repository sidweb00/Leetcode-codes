class Solution {
public:
    
    int dp[1010][110][2];
    // int price[1010];
    vector<int>price;
    int K,n;
    
    int rec(int i,int k,int b){
        
        if(k>K)return -1e9;
        
        if(i==n){
            if(b==1)return -1e9;
            else return 0;
        }
        
        if(dp[i][k][b]!=-1)return dp[i][k][b];
        
        if(b==0){
            dp[i][k][b]=max(rec(i+1,k+1,1)-price[i],rec(i+1,k,0));
        }
        else{
            dp[i][k][b]=max(rec(i+1,k,0)+price[i],rec(i+1,k,1));
        }
        
        return dp[i][k][b];
    }
    
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        price=prices;
        K=k;
        memset(dp,-1,sizeof(dp));
        
        return rec(0,0,0);
        
    }
};