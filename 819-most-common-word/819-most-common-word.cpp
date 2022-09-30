class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        
        string temp="";
        map<string,int>mp;
        for(int i=0;i<paragraph.size();i++){
            
            if(paragraph[i]>='A' && paragraph[i]<='Z'){
                paragraph[i]=tolower(paragraph[i]);
            }
            
            if(paragraph[i]==' ' || ispunct(paragraph[i])){
                if(temp!=""){
                    int flag=0;
                    for(auto s:banned){
                        if(s==temp){
                            flag=1;
                            temp="";
                            break;
                        }

                    }

                    if(!flag){
                        cout<<temp<<"\n";
                        mp[temp]++;
                    }
                    temp="";
                
                }
            }
            else temp.push_back(paragraph[i]);
            
        }
        
            
        if(temp!=""){
            int flag=0;
            for(auto s:banned){
                if(s==temp){
                    flag=1;
                    break;
                }
            }

            if(!flag){
                mp[temp]++;
            }
        }
        
        string s;
        int fm=0;
        for(auto p:mp){
            int f=p.second;
            string t=p.first;
            if(f>fm){
                fm=f;
                s=t;
            }
        }
        
        return s;
    }
};