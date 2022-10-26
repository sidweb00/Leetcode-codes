class Solution {
public:
    string largestPalindromic(string num) {
        int f[10]={};
        
        for(auto v:num){
            f[v-'0']++;
        }
        string ans;
        int flag=1;
        for(int i=9;i>=0;i--){
            if(i!=0){
                while(f[i]!=0 && f[i]>1){
                    ans.push_back(char('0'+i));
                    f[i]-=2;
                    flag=0;
                }
            }
            else if(i==0 && flag==0){
                while(f[i]!=0 && f[i]>1){
                    ans.push_back(char('0'+i));
                    f[i]-=2;
                    flag=0;
                }
            }
            
        }
        
        string start=ans;
        
        for(int i=9;i>=0;i--){
            if(f[i]>=1){
                start.push_back(char('0'+i));
                break;
            }
        }
        
        reverse(ans.begin(),ans.end());
        
        start=start+ans;
        return start;
    }
};