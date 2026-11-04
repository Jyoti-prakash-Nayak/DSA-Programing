class Solution
{
public:
    vector<long long> getWindowCosts(vector<int> &nums, int x)
    {
        multiset<int> low, high;

        long long sumLow = 0, sumHigh = 0;
        vector<long long> cost;

        // low contains the smaller half (including median)
        // high contains the larger half

        auto balance = [&]()
        {
            while (low.size() > high.size() + 1)
            {
                auto it = prev(low.end());
                int val = *it;

                sumLow -= val;
                low.erase(it);

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size())
            {
                auto it = high.begin();
                int val = *it;

                sumHigh -= val;
                high.erase(it);

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val)
        {
            if (low.empty() || val <= *prev(low.end()))
            {
                low.insert(val);
                sumLow += val;
            }
            else
            {
                high.insert(val);
                sumHigh += val;
            }
            balance();
        };

        auto remove = [&](int val)
        {
            auto it = low.find(val);

            if (it != low.end())
            {
                low.erase(it);
                sumLow -= val;
            }
            else
            {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }
            balance();
        };

        for (int i = 0; i < nums.size(); i++)
        {
            add(nums[i]);

            // Remove element outside the window
            if (i >= x)
            {
                remove(nums[i - x]);
            }

            // Window is ready
            if (i >= x - 1)
            {
                long long median = *prev(low.end());

                long long leftCost =
                    median * (long long)low.size() - sumLow;

                long long rightCost =
                    sumHigh - median * (long long)high.size();

                cost.push_back(leftCost + rightCost);
            }
        }

        return cost;
    }

    long long f(int ind, int k, vector<long long> &costs, int x, vector<vector<long long>> &dp)
    {
        if (k == 0)
        {
            return 0;
        }

        if (ind < 0)
        {
            return LLONG_MAX / 4;
        }

        if (dp[ind][k] != -1)
        {
            return dp[ind][k];
        }

        long long notTake = f(ind - 1, k, costs, x, dp);
        long long take = costs[ind] + f(ind - x, k - 1, costs, x, dp);

        return dp[ind][k] = min(take, notTake);
    }
    long long minOperations(vector<int> &nums, int x, int k)
    {
        vector<long long> costs = getWindowCosts(nums, x);
        int n = costs.size();

        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));

        return f(n - 1, k, costs, x, dp);
    }
};