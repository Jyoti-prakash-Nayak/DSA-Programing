class Solution
{
public:
    T.C = O(n)
              S.C = O(n) int
    f(int ind, int n, vector<int> &stoneValue, vector<int> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }

        if (dp[ind] != -1)
        {
            return dp[ind];
        }

        int ans = INT_MIN;
        ans = max(ans, stoneValue[ind] - f(ind + 1, n, stoneValue, dp));
        if (ind + 1 < n)
        {
            ans = max(ans, stoneValue[ind] + stoneValue[ind + 1] - f(ind + 2, n, stoneValue, dp));
        }
        if (ind + 2 < n)
        {
            ans = max(ans, stoneValue[ind] + stoneValue[ind + 1] + stoneValue[ind + 2] - f(ind + 3, n, stoneValue, dp));
        }

        return dp[ind] = ans;
    }
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        vector<int> dp(n + 1, -1);
        int alice = f(0, n, stoneValue, dp);
        if (alice > 0)
        {
            return "Alice";
        }
        else if (alice < 0)
        {
            return "Bob";
        }
        else
        {
            return "Tie";
        }
    }
};