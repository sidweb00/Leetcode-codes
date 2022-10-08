class Solution {
public:
    
    using ll =long long;
    
    struct UnionFind{
      
        ll n;
        vector<ll>rank;
        vector<int>parent;
        
        UnionFind(ll a){
            n=a;
            rank.resize(n+1);
            parent.resize(n+1);
        
            for(int i=1;i<=n;i++){
                parent[i]=i;
                rank[i]=1;
            }
        }
        
        int find(int x){
            if(parent[x]==x)return x;
            return parent[x]=find(parent[x]);
        }
        
        void merge(int x,int y){
            x=find(x);
            y=find(y);
            
            if(x!=y){
                if(rank[x]<=rank[y]){
                    rank[y]+=rank[x];
                    parent[x]=y;
                }
                else{
                    rank[x]+=rank[y];
                    parent[y]=x;
                }    
            }
            
        }
        
    };
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        
        sort(edgeList.begin(),edgeList.end(),[](auto &a,auto &b){return a.back()<b.back();});
        sort(queries.begin(),queries.end(),[](auto &a,auto &b){return a[2]<b[2];});
        
        int i=0;
        
        vector<bool>ans(queries.size());
        
        UnionFind uf(n);
        
        for(auto q:queries){
            ll u=q[0]+1;
            ll v=q[1]+1;
            ll limit=q[2];
            
            while(i<edgeList.size() && edgeList[i][2]<limit){
                ll x=edgeList[i][0]+1;
                ll y=edgeList[i][1]+1;
                uf.merge(x,y);
                i++;
            }
            ans[q.back()]=uf.find(u)==uf.find(v);
        }
        
        return ans;
    }
};