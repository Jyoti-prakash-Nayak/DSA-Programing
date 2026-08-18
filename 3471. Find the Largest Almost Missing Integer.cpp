class Solution
{
public:
    int largestInteger(vector<int> &nums, int k)
    {
        int n = nums.size();
        map<int, int> mp;
        for (auto it : nums)
        {
            mp[it]++;
        }

        if (k == 1)
        {
            for (auto it = mp.rbegin(); it != mp.rend(); it++)
            {
                if (it->second == 1)
                {
                    return it->first;
                }
            }
        }

        if (k == n)
        {
            return *max_element(nums.begin(), nums.end());
        }

        int a = nums[0];
        int b = nums[n - 1];
        if (a > b)
        {
            swap(a, b);
        }
        auto first = mp[a];
        auto last = mp[b];
        if (last == 1)
        {
            return b;
        }
        else if (first == 1)
        {
            return a;
        }

        return -1;
    }
};