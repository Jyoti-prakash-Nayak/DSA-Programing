class Solution
{
public:
    // T.C=O(2^n)
    // S.C=O(n)
    int f(int i, int j, vector<int> &nums)
    {
        if (i > j)
        {
            return 0;
        }

        if (i == j)
        {
            return nums[i];
        }

        int take_left = nums[i] + min(f(i + 2, j, nums), f(i + 1, j - 1, nums));
        int take_right = nums[j] + min(f(i + 1, j - 1, nums), f(i, j - 2, nums));

        return max(take_left, take_right);
    }
    bool predictTheWinner(vector<int> &nums)
    {
        int n = nums.size();

        int total = 0;
        for (auto it : nums)
        {
            total += it;
        }

        int total1 = f(0, n - 1, nums);
        int total2 = total - total1;

        return total1 >= total2;
    }
};