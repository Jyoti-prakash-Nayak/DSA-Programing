class Solution
{
public:
    int n, m;
    int DR[4] = {-1, 1, 0, 0};
    int DC[4] = {0, 0, -1, 1};
    bool isValid(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &mat)
    {
        if (r < 0 || r >= n || c < 0 || c >= m && mat[r][c] == 0 || vis[r][c] == 1)
        {
            return 0;
        }

        for (int k = 0; k < 4; k++)
        {
            int newR = r + DR[k];
            int newC = c + DC[k];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m && mat[newR][newC] == 0)
            {
                return 0;
            }
        }
        return 1;
    }
    int shortestPath(vector<vector<int>> &mat)
    {
        // code here
        n = mat.size();
        m = mat[0].size();

        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {
            if (isValid(i, 0, vis, mat))
            {
                vis[i][0] = 1;
                q.push({i, 0});
            }
        }

        int ans = 1;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                if (c == m - 1)
                {
                    return ans;
                }

                for (int k = 0; k < 4; k++)
                {
                    int newR = r + DR[k];
                    int newC = c + DC[k];

                    if (isValid(newR, newC, vis, mat))
                    {
                        vis[newR][newC] = 1;
                        q.push({newR, newC});
                    }
                }
            }
            ans++;
        }

        return -1;
    }
};