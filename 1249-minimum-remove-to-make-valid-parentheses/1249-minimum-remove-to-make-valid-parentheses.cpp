class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int val=0;
        int n=s.length();

        for(int i=0;i<n;i++){
            if(s[i]=='(')val++;
            else if(s[i]==')'){
                //std::cout<<val;
                val--;
                if(val<0){
                    s[i]='*';
                    val++;
                }
                //std::cout<<val;
            }
        }
        //std::cout<<val;
        if(val>0){
            for(int i=n-1;i>=0;i--){
                if(s[i]=='('){
                    s[i]='*';
                    val--;
                }
                if(val==0)break;
            }
        }
        string ans;
        for(int i=0;i<n;i++){
            if(s[i]!='*')ans.push_back(s[i]);
        }
        
        return ans;
    }
};