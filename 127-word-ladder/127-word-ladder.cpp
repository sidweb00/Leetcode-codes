class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string>q;
        q.push(beginWord);
        
        int ans =1;
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=0;i<n;i++){
                string s=q.front();
                q.pop();
                
                if(s==endWord)return ans;
                
                dict.erase(s);
                
                for(int k=0;k<s.length();k++){
                    char c=s[k];
                    
                    for(int j=0;j<26;j++){
                        s[k]='a'+j;
                        
                        if(dict.find(s)!=dict.end()){
                            q.push(s);
                        }     
                    }
                    
                    s[k]=c;
                }
            }
            ans++;   
        }
        return 0;
    }
};