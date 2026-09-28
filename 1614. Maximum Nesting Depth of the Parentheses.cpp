class Solution
{
public:
    int maxDepth(string s)
    {
        int openBracket = 0;
        int closeBracket = 0;
        int n = s.size();
        int ans = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                openBracket++;
            }
            else if (s[i] == ')')
            {
                openBracket--;
            }
            ans = max(ans, openBracket);
        }
        return ans;
    }
};