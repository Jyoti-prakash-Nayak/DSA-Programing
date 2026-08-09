// T.C=O(n^3)
// S.C=O(n^2)
class Solution
{
public:
    // Alice=(person==1)
    // Bob=(person==0)
    int n;
    int f(vector<int> &piles, int person, int ind, int M, vector<vector<vector<int>>> &dp)
    {
        if (ind >= n)
        {
            return 0;
        }

        int res = (person == 1) ? -1 : INT_MAX;
        int stone = 0;

        if (dp[person][ind][M] != -1)
        {
            return dp[person][ind][M];
        }

        for (int x = 1; x <= min(2 * M, n - ind); x++)
        {
            stone += piles[ind + x - 1];

            if (person)
            {
                res = max(res, stone + f(piles, 0, ind + x, max(M, x), dp));
            }
            else
            {
                res = min(res, f(piles, 1, ind + x, max(M, x), dp));
            }
        }

        return dp[person][ind][M] = res;
    }
    int stoneGameII(vector<int> &piles)
    {
        n = piles.size();
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return f(piles, 1, 0, 1, dp);
    }
};