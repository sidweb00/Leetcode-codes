class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        int i=0,j=-1;
        
        int kmp[n+1];
        kmp[0]=-1;
        // int ans =0;
        // int maxi=0;
        while(i<n){
            while(j!=-1 && s[i]!=s[j])j=kmp[j];
            i++;
            j++;
            kmp[i]=j;
            // ans=max(ans,kmp[i]);
        }
        // for(int i=0;i<=n;i++){
        //     cout<<kmp[i]<<" ";
        // }
        // return "";
        return s.substr(0,kmp[n]);
    }
};