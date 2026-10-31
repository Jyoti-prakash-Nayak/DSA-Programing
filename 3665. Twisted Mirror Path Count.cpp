class Solution {
public:
    int n,m;
    const int mod=1e9+7;
    int dp[501][501][2];
    int f(int i,int j,bool isRight,vector<vector<int>>& grid){
    
        if(i==n-1 && j==m-1){
            return 1;
        }
        if(i>=n || j>=m){
            return 0;
        }

        if(dp[i][j][isRight]!=-1){
            return dp[i][j][isRight];
        }

        if(grid[i][j]==1){
            if(isRight==true){
                return f(i+1,j,false,grid);
            }else{
                return f(i,j+1,true,grid);
            }
        }

        int right=f(i,j+1,true,grid);
        int down=f(i+1,j,false,grid);

        return dp[i][j][isRight]=(right+down)%mod;
    }
    int uniquePaths(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        
        memset(dp,-1,sizeof(dp));

        int count=0;
        if(grid[0][0]==1){
          count+=f(0,0,true,grid);
          count+=f(0,0,false,grid);
        }

        count=f(0,0,true,grid);

        return count;
    }
};