// Time Complexity  : O(n log n)
// Space Complexity : O(n)
struct Interval
{
    int l;
    int r;
    int weight;
    int index;
};
struct Result
{
    long long score;
    vector<int> indices;
};

class Solution
{
public:
    // checking which one is better
    Result better(Result a, Result b)
    {
        // Higher score is better
        if (a.score != b.score)
        {
            return (a.score > b.score) ? a : b;
        }

        // Same score -> lexicographically smaller indices
        sort(a.indices.begin(), a.indices.end());
        sort(b.indices.begin(), b.indices.end());

        if (a.indices < b.indices)
            return a;
        return b;
    }
    vector<int> maximumWeight(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<Interval> interval;
        for (int i = 0; i < n; i++)
        {
            int l = intervals[i][0];
            int r = intervals[i][1];
            int wt = intervals[i][2];
            int idx = i;

            interval.push_back({l, r, wt, idx});
        }

        // Sort by starting point
        // Sorting       O(n log n)
        sort(interval.begin(), interval.end(),
             [](const Interval &a, const Interval &b)
             {
                 if (a.l != b.l)
                     return a.l < b.l;
                 return a.r < b.r;
             });

        vector<int> next(n);
        // Binary search O(n log n)
        for (int i = 0; i < n; i++)
        {
            int lo = i + 1;
            int hi = n;

            while (lo < hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (interval[mid].l > interval[i].r)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i][k]
        // Starting from i, choose at most k intervals
        vector<vector<Result>> dp(n + 1, vector<Result>(5));

        // Base case: no intervals -> score 0
        for (int k = 0; k <= 4; k++)
        {
            dp[n][k] = {0, {}};
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int k = 1; k <= 4; k++)
            {
                Result skip = dp[i + 1][k];

                Result take = dp[next[i]][k - 1];

                take.score += interval[i].weight;
                take.indices.push_back(interval[i].index);

                dp[i][k] = better(take, skip);
            }
        }

        vector<int> ans = dp[0][4].indices;
        sort(ans.begin(), ans.end());
        return ans;
    }
};