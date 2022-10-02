class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26]={0};
        int n=s.length();
        for(int i=0;i<s.length();i++){
            last[s[i]-'a']=i;
        }
        for(int i=0;i<26;i++){
            cout<<last[i]<<" ";
        }
        
        vector<int>ans;
        int curm=0,mark=0;
        for(int i=0;i<n;i++){
            curm=max(curm,last[s[i]-'a']);
            if(curm==i){
                // cnt++;
                ans.push_back(i+1-mark);
                mark=i+1;
            }
        }
        
        return ans;
    }
};