class Solution {
public:
    int dp[100][100][201];
    int n,m;
    bool dfs(int i,int j,int balance,vector<vector<char>>&grid){
        if(i>=n || j>=m){
            return false;
        }

        if(grid[i][j]=='('){
            balance++;
        }else{
            balance--;
        }

        if(balance < 0){
            return false;
        }

        if(dp[i][j][balance]!=-1){
            return dp[i][j][balance];
        }

        if(i==n-1 && j==m-1){
            return dp[i][j][balance]=(balance==0);
        }

        bool down=dfs(i+1,j,balance,grid);
        bool right=dfs(i,j+1,balance,grid);

        return dp[i][j][balance]=(down || right);
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        n=grid.size();
        m=grid[0].size();

        if((n+m-1)%2!=0){
            return false;
        }

        if(grid[0][0]==')' || grid[n-1][m-1]=='('){
            return false;
        }

        memset(dp,-1,sizeof(dp));

        return dfs(0,0,0,grid);
    }
};