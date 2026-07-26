class Solution
{
public:
    // T.C=O(N logN)
    // S.C=O(1)
    int maximumProduct(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // take last 3 elements and if there is negative elements thats 2 -ve element prod is +ve so we also take 1st 2 -ve and last large +ve
        return max(nums[n - 1] * nums[n - 2] * nums[n - 3], nums[0] * nums[1] * nums[n - 1]);
    }
};