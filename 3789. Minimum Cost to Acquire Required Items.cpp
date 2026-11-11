class Solution
{
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2)
    {
        long long ans = 0;
        // case 1
        if (cost1 + cost2 <= costBoth)
        {
            ans = 1LL * need1 * cost1 + 1LL * need2 * cost2;
        }
        // case 2
        else
        {

            // first use costBoth untill one of need is zero
            ans += 1LL * min(need1, need2) * costBoth;
            // choose minimum between corresponding cost and costBoth
            if (need1 > need2)
            {
                ans += 1LL * min(cost1, costBoth) * (need1 - need2);
            }
            else if (need1 < need2)
            {
                ans += 1LL * min(cost2, costBoth) * (need2 - need1);
            }
        }
        return ans;
    }
};