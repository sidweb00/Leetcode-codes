class Solution {
public:
    
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,1,-1};
    
    int n,m;
    
    int check(int x,int y,vector<vector<char>>& grid){
        if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!='0'){
            return 1;
        }
        return 0;
    }
    
    int vis[330][330];
    
    void dfs(int i,int j,vector<vector<char>>& grid){
        
        vis[i][j]=1;
        
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(check(x,y,grid) && !vis[x][y]){
                dfs(x,y,grid);
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size(); 
        int cnt =0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(i,j,grid) && !vis[i][j]){
                    dfs(i,j,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};