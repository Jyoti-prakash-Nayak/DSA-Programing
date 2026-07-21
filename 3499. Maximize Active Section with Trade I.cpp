// Approach (target 1s and find max pair sum of zero blocks)
// T.C : O(n)
// S.C : O(n)
class Solution
{
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int n = s.size();
        int oneCount = count(begin(s), end(s), '1');
        vector<int> zeroCount;

        int i = 0;
        while (i < n)
        {
            if (s[i] == '0')
            {
                int start = i;
                while (i < n && s[i] == '0')
                {
                    i++;
                }

                zeroCount.push_back(i - start);
            }
            else
            {
                i++;
            }
        }

        int maxiPair = 0;
        for (int i = 1; i < zeroCount.size(); i++)
        {
            maxiPair = max(maxiPair, zeroCount[i - 1] + zeroCount[i]);
        }

        return oneCount + maxiPair;
    }
};