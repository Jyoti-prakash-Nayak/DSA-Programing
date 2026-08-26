class Solution
{
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        int n = s.size();

        string ans = "";
        int one = 0;
        int i = 0;

        for (int j = 0; j < n; j++)
        {
            if (s[j] == '1')
            {
                one++;
            }

            while (one > k)
            {
                if (s[i] == '1')
                {
                    one--;
                }
                i++;
            }

            while (i <= j && s[i] == '0')
            {
                i++;
            }

            if (one == k)
            {
                string curr = s.substr(i, j - i + 1);

                if (ans.empty() || (curr.size() < ans.size()) || (curr.size() == ans.size() && curr < ans))
                {
                    ans = curr;
                }
            }
        }
        return ans;
    }
};