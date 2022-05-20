class Solution {
public:
    
    int x;
    vector<string>ans;
    
    void rec(int open,int close,string temp){
        //std::cout<<"y";
        if(open<x){
            temp.push_back('(');
            rec(open+1,close,temp);
            temp.pop_back();
        }
        
        if(close<open){
            temp.push_back(')');
            rec(open,close+1,temp);
            if(temp.size()==2*x){
                ans.push_back(temp);
            }
            temp.pop_back();
        }
        
    }
    
    vector<string> generateParenthesis(int n) {
        x=n;
        rec(0,0,"");
        return ans;
    }
};