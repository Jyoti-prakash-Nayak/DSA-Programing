// T.C=O(n³)
// S.C=O(n²)
class Solution
{
public:
    int dp[501][501];
    int f(int s, int e, vector<int> &stoneValue)
    {
        if (s >= e)
        {
            return 0;
        }

        if (dp[s][e] != -1)
        {
            return dp[s][e];
        }

        int right = 0;
        for (int i = s; i <= e; i++)
        {
            right += stoneValue[i];
        }

        int left = 0;
        int ans = 0;
        for (int i = s; i < e; i++)
        {
            left += stoneValue[i];
            right -= stoneValue[i];

            if (left < right)
            {
                ans = max(ans, left + f(s, i, stoneValue));
            }
            if (left == right)
            {
                ans = max(ans, left + max(f(s, i, stoneValue), f(i + 1, e, stoneValue)));
            }
            if (right < left)
            {
                ans = max(ans, right + f(i + 1, e, stoneValue));
            }
        }
        return dp[s][e] = ans;
    }
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();
        memset(dp, -1, sizeof(dp));
        return f(0, n - 1, stoneValue);
    }
};