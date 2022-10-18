class Solution {
public:
    
    int dp[110][110][110];
    vector<int>box;
    
    int rec(int l,int r,int k){
        
        if(l>r)return 0;
        
        if(dp[l][r][k]!=-1)return dp[l][r][k];
        
        
        dp[l][r][k]=rec(l+1,r,0)+(k+1)*(k+1);
        
        for(int j=l+1;j<=r;j++){
            if(box[l]==box[j])dp[l][r][k]=max(dp[l][r][k],rec(j,r,k+1)+rec(l+1,j-1,0));
        }
        
        return dp[l][r][k];
    }
    
    int removeBoxes(vector<int>& boxes) {
        memset(dp,-1,sizeof(dp));
        box=boxes;
        return rec(0,boxes.size()-1,0);
    }   
};