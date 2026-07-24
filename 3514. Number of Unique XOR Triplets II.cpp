class Solution
{
public:
    // T.C=O(n^3)
    // S.C=O(n^3)
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        unordered_set<int> st1, st2;

        if (n == 1)
            return n;

        // Pair Xors
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                st1.insert(nums[i] ^ nums[j]);
            }
        }

        // XOR each pair XOR with every element
        for (auto it : st1)
        {
            for (auto x : nums)
            {
                st2.insert(x ^ it);
            }
        }

        return st2.size();
    }
};