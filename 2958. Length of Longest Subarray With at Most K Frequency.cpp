// T.C=O(n)
// S.C=O(n)
class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> mp;

        int i = 0;
        int maxiLength = 0;

        for (int j = 0; j < n; j++)
        {
            int val = nums[j];
            mp[val]++;

            while (mp[val] > k)
            {
                mp[nums[i]]--;
                i++;
            }

            if (mp[val] <= k)
            {
                maxiLength = max(maxiLength, j - i + 1);
            }
        }

        return maxiLength;
    }
};