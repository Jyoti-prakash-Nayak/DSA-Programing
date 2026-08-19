class Solution
{
public:
    bool checkTwo(vector<int> &a)
    {
        for (int i = 1; i <= 8; i++)
        {
            if (a[i] == 1)
            {
                return false;
            }
        }
        return true;
    }
    bool checkOne(vector<int> &a)
    {
        int total = 0;
        for (int i = 1; i <= 4; i++)
        {
            if (a[i] != 1)
            {
                total++;
            }
        }
        if (total == 4)
        {
            return true;
        }
        total = 0;
        for (int i = 3; i <= 6; i++)
        {
            if (a[i] != 1)
            {
                total++;
            }
        }
        if (total == 4)
        {
            return true;
        }
        total = 0;
        for (int i = 5; i <= 8; i++)
        {
            if (a[i] != 1)
            {
                total++;
            }
        }
        if (total == 4)
        {
            return true;
        }
        return false;
    }
    int maxNumberOfFamilies(int n, vector<vector<int>> &rs)
    {
        sort(rs.begin(), rs.end());
        rs.push_back({(int)1e9 + 7, 1});
        int last = -1;
        int rows = -1, total = 0;
        vector<int> a(10, 1);
        for (int i = 0; i < rs.size(); i++)
        {
            if (rs[i][0] == last)
            {
                a[rs[i][1] - 1] = 1;
            }
            else
            {
                rows++;
                if (checkTwo(a))
                {
                    total += 2;
                }
                else if (checkOne(a))
                {
                    total += 1;
                }
                a = vector<int>(10, 0);
                a[rs[i][1] - 1] = 1;
                last = rs[i][0];
            }
        }

        return 2 * (n - rows) + total;
    }
};