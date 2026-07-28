class Solution
{
public:
    // T.C=O(n)
    // S.C=O(n)
    string smallestPalindrome(string s)
    {
        int n = s.size();
        map<char, int> mp; // O(n)
        for (int i = 0; i < n; i++)
        { // O(n logk) here k=26 so //O(n)
            mp[s[i]]++;
        }

        string str;
        bool isOddPresent = false;
        char extraOddChar;
        for (auto it : mp)
        { // O(n)
            char c = it.first;
            int cnt = it.second;

            if (cnt % 2 != 0)
            {
                isOddPresent = true;
                extraOddChar = c;
            }

            int halfCnt = cnt / 2;
            str.append(halfCnt, c); // O(n)
        }

        string revStr = str;                   // O(n)
        reverse(revStr.begin(), revStr.end()); // O(n)
        if (isOddPresent)
        {
            str.append(1, extraOddChar);
        }

        return str + revStr;
    }
};