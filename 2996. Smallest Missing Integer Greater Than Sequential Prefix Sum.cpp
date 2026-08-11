// T.C=O(n)
// S.C=O(n)
class Solution
{
public:
    int missingInteger(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st;
        for (auto it : nums)
        {
            st.insert(it);
        }

        int sum = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] + 1 == nums[i])
            {
                sum += nums[i];
            }
            else
            {
                break;
            }
        }

        int x = sum;
        while (st.count(x))
        {
            x++;
        }

        return x;
    }
};