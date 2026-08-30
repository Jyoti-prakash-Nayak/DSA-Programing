class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();

        int miniValInd = 0;
        int maxiValInd = 0;
        int miniVal = nums[0];
        int maxiVal = nums[0];
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > maxiVal)
            {
                maxiVal = nums[i];
                maxiValInd = i;
            }
            else if (nums[i] < miniVal)
            {
                miniVal = nums[i];
                miniValInd = i;
            }
        }

        int firstRemoveMini = miniValInd + 1;
        int lastRemoveMini = n - miniValInd;

        int firstRemoveMaxi = maxiValInd + 1;
        int lastRemoveMaxi = n - maxiValInd;

        // Both from front
        int a = max(firstRemoveMini, firstRemoveMaxi);

        // Both from back
        int b = max(lastRemoveMini, lastRemoveMaxi);

        // Min from front, Max from back
        int c = firstRemoveMini + lastRemoveMaxi;

        // Max from front, Min from back
        int d = firstRemoveMaxi + lastRemoveMini;

        return min({a, b, c, d});
    }
};