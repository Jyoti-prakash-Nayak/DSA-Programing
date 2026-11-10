class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,0);
      
        for(int i=n-1;i>=0;i--){
           int oneStep=INT_MAX;
           if(i<n){
             oneStep=costs[i]+1+dp[i+1];
           }

           int twoStep=INT_MAX;
           if(i+1 < n){
             twoStep=costs[i+1]+4+dp[i+2];
           }

           int threeStep=INT_MAX;
           if(i+2 < n){
             threeStep=costs[i+2]+9+dp[i+3];
           }
           
           dp[i]=min({oneStep,twoStep,threeStep});

        }
        return dp[0];
    }
};