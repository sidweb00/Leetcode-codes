class Solution {
public:
    int nthUglyNumber(int n) {
        int ugly[n+1];
        
        ugly[1]=1;
        int r=1,j=1,k=1;
        
        for(int i=2;i<=n;i++){
            ugly[i]=min({ugly[r]*2,ugly[j]*3,ugly[k]*5});
            
            if(ugly[i]==ugly[r]*2)r++;
            if(ugly[i]==ugly[j]*3)j++;
            if(ugly[i]==ugly[k]*5)k++;
        }
        
        return ugly[n];
    }
};