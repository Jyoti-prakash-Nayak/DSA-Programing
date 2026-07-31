class Solution
{
public:
    // T.C=O(n)
    // S.C=O(1)
    int minimumPushes(string word)
    {
        unordered_map<char, int> mp;
        for (auto c : word)
        {
            mp[c]++;
        }

        vector<int> temp;
        for (auto it : mp)
        {
            temp.push_back(it.second);
        }

        sort(temp.begin(), temp.end(), greater<>());

        int cnt = 0;
        for (int i = 0; i < temp.size(); i++)
        {
            cnt += temp[i] * (i / 8 + 1);
        }
        return cnt;
    }
};