class Solution
{
public:
    // T.C=O(10 logN)
    // S.C=O(1)
    int prodDigit(int m)
    {
        int res = 1;
        while (m)
        {
            int digit = m % 10;
            res = res * digit;
            m = m / 10;
        }
        return res;
    }
    int smallestNumber(int n, int t)
    {
        int ans = 0;
        for (int i = n; i < n + 10; i++)
        {
            int val = prodDigit(i);
            if (val % t == 0)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};