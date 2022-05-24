class Solution {
public:
    bool canBeValid(string s, string locked) {
        
        int lo=0,hi=0;
        int n=s.length();
        
        if(n%2)return 0;
        
        for(int i=0;i<n;i++){
            if(locked[i]=='0'){
                lo--;
                hi++;
            }
            else{
                lo+= (s[i]=='(')? 1:-1;
                hi+= (s[i]!=')')?1:-1;
            }
            
            if(hi<0)return 0;
            lo=max(lo,0);
        }
        
        return lo==0;
    }
};