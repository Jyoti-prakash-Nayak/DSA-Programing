class Solution
{
public:
    int uniqueXorTriplets(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
        {
            return n;
        }

        int temp = n;
        int cnt = 0;
        while (temp > 0)
        {
            temp >>= 1;
            cnt++;
        }
        return pow(2, cnt);
    }
};