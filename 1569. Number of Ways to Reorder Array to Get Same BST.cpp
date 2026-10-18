class Solution {
public:
   typedef long long ll;
    vector<vector<ll>>dp;
     
    ll mod=1e9+7;
    
    ll solve(vector<int>&nums){
        int n=nums.size();
        vector<int>left,right;
        if(n<3){
            return 1;
        }

        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root){
              left.push_back(nums[i]);
            }else{
                right.push_back(nums[i]);
            }
        }

        ll x=solve(left)%mod;
        ll y=solve(right)%mod;

        ll z=dp[n-1][left.size()]%mod;

        return ((x*y)%mod  * z)%mod;
    }
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n);
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
            dp[i][0]=1;
            dp[i][i]=1;
            for(int j=1;j<i;j++){
                dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
            }
        }

        return (solve(nums) - 1 + mod) % mod;
    }
};