class Solution {
public:
    bool checkValidString(string s) {
        
        int lo=0,hi=0;
        
        for(auto c : s){
            lo+= (c=='(')? 1:-1;
            hi+= (c!=')')? 1:-1;
            lo=max(lo,0);
            if(hi<0)return 0;
        }
        return lo==0;
    }
};