class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int biggest = 0;
        int secondBiggest = 0;

        for (auto num : nums)
        {
            if (num > biggest)
            {
                secondBiggest = biggest;
                biggest = num;
            }
            else
            {
                secondBiggest = max(secondBiggest, num);
            }
        }

        return (biggest - 1) * (secondBiggest - 1);
    }
};