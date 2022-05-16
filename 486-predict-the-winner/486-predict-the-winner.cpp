class Solution {
public:
    
    vector<int>a;
    int dp[25][25];
    
    int rec(int l,int r){
            
        if(l>r)return 0;
        if(dp[l][r]!=-1)return dp[l][r];
        return dp[l][r]=max(a[l]-rec(l+1,r),a[r]-rec(l,r-1));
        
    }
    
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        a=nums;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dp[i][j]=-1;
            }
        }
        std::cout<<rec(0,n-1);
        if( rec(0,n-1)>=0)return 1;
        return 0;
    }
};