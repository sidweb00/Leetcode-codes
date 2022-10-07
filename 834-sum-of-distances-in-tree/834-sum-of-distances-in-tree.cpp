class Solution {
public:
    
    
    vector<int>g[30030];
    int N;
    int parent[30030];
    int subsiz[30030];
    int subsum[30030];
    
    
    void dfs(int node,int par){
        parent[node]=par;

        
        subsiz[node]=1;
        subsum[node]=0;
        for(auto v:g[node]){
            if(v!=par){
                dfs(v,node);
                subsiz[node]+=subsiz[v];
                subsum[node]+=subsiz[v]+subsum[v];
            }
        }
    }
    
    vector<int>ans;
    
    void dfs2(int node,int par){
        
        if(node!=1)ans[node]=ans[par]-2*subsiz[node]+N;
        
        for(auto v:g[node]){
            if(v!=par)dfs2(v,node);
        }
        
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        
        N=n;
        
        for(auto v:edges){
            int u=v[0]+1;
            int p=v[1]+1;
            g[u].push_back(p);
            g[p].push_back(u);
        }
        
        dfs(1,0);
        
        ans.resize(n+1);
        ans[1]=subsum[1];
        
        dfs2(1,0);
        ans.erase(ans.begin());
        return ans;
        
    }
};