class Solution {
public:
    int minSteps(int n) {
        int ans=0;
        int p=2;
        
        while(n>1){
            while(n%p==0){
                ans+=p;
                n/=p;
            }    
            p++;
        }
        
        return ans;
    }
};