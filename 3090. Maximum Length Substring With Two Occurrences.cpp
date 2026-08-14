class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        unordered_map<char, int> mp;

        int i = 0;
        int maxi = 0;
        for (int j = 0; j < n; j++)
        {
            mp[s[j]]++;

            while (mp[s[j]] > 2)
            {
                mp[s[i]]--;
                if (mp[s[i]] == 0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }

            maxi = max(maxi, j - i + 1);
        }

        return maxi;
    }
};