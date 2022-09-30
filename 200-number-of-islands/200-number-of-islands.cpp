class Solution {
public:
    
    int dx[4]={0,-1,0,1};
    int dy[4]={1,0,-1,0};
    
    int vis[330][330];
    
    int n,m;
    vector<vector<char>> a;
    
    int check(int x,int y){
        if(x<n && x>=0 && y<m && y>=0 && a[x][y]=='1')return 1;
        return 0;
    }
    
    void dfs(int i,int j){
        vis[i][j]=1;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            
            if(check(x,y) && !vis[x][y]){
                dfs(x,y);
            }
            
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();
        a=grid;
        
        int cnt=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && check(i,j)){
                    // cout<<i<<" "<<j<<" ";
                    dfs(i,j);
                    cnt++;
                }
                // cout<<"\n";
            }
        }
        
        return cnt;
    }
};