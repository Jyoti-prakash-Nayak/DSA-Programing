class Solution
{
public:
    string answer = "";
    bool found = false;
    int n;
    void f(int pos, string &current, vector<int> &freq, string &target, bool isGreater)
    {
        if (found)
        {
            return;
        }

        if (pos == n)
        {
            if (isGreater)
            {
                answer = current;
                found = true;
            }
            return;
        }

        for (int i = 0; i < 26; i++)
        {
            if (freq[i] == 0)
            {
                continue;
            }

            char ch = 'a' + i;

            if (!isGreater && ch < target[pos])
            {
                continue;
            }

            freq[i]--;
            current.push_back(ch);
            if (ch > target[pos])
            {
                isGreater = true;
            }
            f(pos + 1, current, freq, target, isGreater);

            current.pop_back();
            freq[i]++;

            if (found)
            {
                return;
            }
        }
    }
    string lexGreaterPermutation(string s, string target)
    {
        n = target.size();
        sort(s.begin(), s.end());
        if (s > target)
        {
            return s;
        }
        vector<int> freq(26, 0);
        for (auto c : s)
        {
            freq[c - 'a']++;
        }

        string current = "";
        f(0, current, freq, target, false);
        return answer;
    }
};