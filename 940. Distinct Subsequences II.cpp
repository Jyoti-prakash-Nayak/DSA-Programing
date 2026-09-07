//T.C=O(n*n)
//S.C=O(n)
class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        int n=s.size();
        vector<int>dp(n+1,0);
        for(int i=n-1;i>=0;i--){
            vector<int>seen(26);
            int ans=0;
            for(int j=i;j<n;j++){
              if(seen[s[j]-'a']){
                continue;
              }

              seen[s[j]-'a']=1;
              ans=(ans+1+dp[j+1])%mod;
            }
           dp[i]=ans;
        }
        return dp[0];
    }
};