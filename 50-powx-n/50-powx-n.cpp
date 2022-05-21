class Solution {
public:
    double myPow(double x, int n) {
        double ans =1;
        long long int temp=n;
        if(n<0)temp*=-1;
        
        while(temp!=0){
            if(temp%2){
                ans*=x;
            }
            x*=x;
            temp/=2;
        }
        
        if(n<0){
            //std::cout<<"-1";
            ans=1/ans;
        }
        
        return ans ;
    }
};