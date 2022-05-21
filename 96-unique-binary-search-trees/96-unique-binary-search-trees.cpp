class Solution {
public:
    
    long long int nCk(int n,int k){
        long long int ans =1;
        
        for(int i=0;i<k;i++){
            ans*=(n-i);
            ans/=(i+1);
        }
        
        return ans;
    }
    
    int numTrees(int n) {
        return nCk(2*n,n)/(n+1);
    }
};