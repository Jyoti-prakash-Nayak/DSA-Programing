class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int num = n;
        int sum = 0;
        int prod = 1;
        while (num)
        {
            int digit = num % 10;
            sum += digit;
            prod *= digit;
            num = num / 10;
        }

        return (n % (sum + prod) == 0);
    }
};