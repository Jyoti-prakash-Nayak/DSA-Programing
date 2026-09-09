class Solution
{
public:
    long countDigit(long n)
    {
        long sum = 0;
        while (n)
        {
            int digit = n % 10;
            sum += digit;
            n = n / 10;
        }
        return sum;
    }
    int findMax(int n)
    {
        // code Here
        long maxiSum = countDigit(n);
        int result = n;

        int temp = n;
        int multiplier = 1;

        while (temp > 0)
        {
            long candidate = (temp - 1) * multiplier + (multiplier - 1);

            long currSum = countDigit(candidate);

            if ((currSum > maxiSum) || (currSum == maxiSum && candidate > result))
            {
                maxiSum = currSum;
                result = (int)candidate;
            }

            temp /= 10;
            multiplier *= 10;
        }

        return result;
    }
};
