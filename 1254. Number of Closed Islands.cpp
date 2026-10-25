class Solution {
public:
    int n,m;
    int DR[4]={1,0,-1,0};
    int DC[4]={0,1,0,-1};
    bool isValid(int r,int c){
       if(r>=0 && r<n && c>=0 && c<m){
        return true;
       }
       return false;
    }
    void dfs(int r,int c,vector<vector<int>>&vis,vector<vector<int>>& grid){
        vis[r][c]=1;

        for(int k=0;k<4;k++){
            int newR=r+DR[k];
            int newC=c+DC[k];

            if(isValid(newR,newC) && vis[newR][newC]==0 && grid[newR][newC]==0){
                dfs(newR,newC,vis,grid);
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();

        vector<vector<int>>vis(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i*j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==0){
                        dfs(i,j,vis,grid);
                    }
                }
            }
        }


        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    cnt++;
                    dfs(i,j,vis,grid);
                }
            }
        }

        return cnt;
    }
};