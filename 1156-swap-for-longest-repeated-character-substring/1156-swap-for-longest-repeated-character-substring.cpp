class Solution {
public:
    int maxRepOpt1(string text) {
        //aaabbbbcccdddaa
        int freq[26]={0};
        int n=text.length();
        vector<int>left(n,0);
        vector<int>right(n,0);
        
        int cnt=1;
        int maxi=1;
        for(int i=0;i<n;i++){
            freq[text[i]-'a']++;
            if(i>0){
                if(text[i-1]==text[i])cnt++;
                else cnt=1;
            }
            left[i]=cnt;
            maxi=max(maxi,cnt);
        }
        cnt=1;
        for(int i=n-1;i>=0;i--){
            if(i<n-1){
                if(text[i+1]==text[i]){
                    cnt++;
                }
                else cnt=1;
            }
            right[i]=cnt;
        }
        
        for(int i=0;i<n;i++){
            if(i>0 && i<n-1){
                    if(text[i-1]==text[i+1] && text[i]!=text[i-1]){
                    if(freq[text[i-1]-'a']==left[i-1]+right[i+1]){
                        maxi=max(maxi,left[i-1]+right[i+1]);
                    }
                    else{
                        maxi=max(maxi,left[i-1]+right[i+1]+1);
                    }
                }
                else{
                    if(freq[text[i]-'a']==left[i]){
                        maxi=max(maxi,left[i]);
                        }
                    else{
                        maxi=max(maxi,left[i]+1);
                    }
                }
            }
            else{
                if(freq[text[i]-'a']==left[i]){
                    maxi=max(maxi,left[i]);
                }
                else{
                    maxi=max(maxi,left[i]+1);
                }
            }
            
            
        }
        return maxi;
    }
};