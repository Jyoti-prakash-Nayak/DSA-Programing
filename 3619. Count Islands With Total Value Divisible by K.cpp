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
    void dfs(int r,int c,long long &sum,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[r][c]=1;
        sum+=grid[r][c];
        
        for(int k=0;k<4;k++){
            int newR=r+DR[k];
            int newC=c+DC[k];

            if(isValid(newR,newC) && grid[newR][newC]!=0 && vis[newR][newC]==0){
                dfs(newR,newC,sum,grid,vis);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0 && vis[i][j]==0){
                    long long sum=0;
                    dfs(i,j,sum,grid,vis);
                    if(sum%k==0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};