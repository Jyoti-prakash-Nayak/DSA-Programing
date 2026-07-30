class Solution
{
public:
    // T.C=O(1)
    // S.C=O(1)
    int minimumPushes(string word)
    {
        int n = word.size();
        int k = n;
        int numberOfPush = 1;
        int cnt = 0;
        while (k)
        {
            if (k <= 8)
            {
                cnt += (k * numberOfPush);
                k = 0;
            }
            else
            {
                cnt += (8 * numberOfPush);
                numberOfPush++;
                k -= 8;
            }
        }
        return cnt;
    }
};