class Solution
{
public:
    int n;
    int solve(int ind, vector<int> &stones, vector<int> &dp)
    {
        if (ind == n - 1)
        {
            return stones[ind];
        }

        if (dp[ind] != INT_MIN)
        {
            return dp[ind];
        }

        int alice_cont = solve(ind + 1, stones, dp);
        int alice_done = stones[ind] - solve(ind + 1, stones, dp);

        return dp[ind] = max(alice_cont, alice_done);
    }
    int stoneGameVIII(vector<int> &stones)
    {
        n = stones.size();

        for (int i = 1; i < n; i++)
        {
            stones[i] = stones[i - 1] + stones[i];
        }

        vector<int> dp(n, INT_MIN);
        return solve(1, stones, dp);
    }
};