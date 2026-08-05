class Solution
{
public:
    // T.C=O(n+m)
    // S.C=O(n+m)
    vector<int> remainingMethods(int n, int k, vector<vector<int>> &invocations)
    {
        vector<vector<int>> adj(n);
        for (auto it : invocations)
        {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(k);

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            for (auto v : adj[node])
            {
                if (!vis[v])
                {
                    q.push(v);
                }
            }
        }

        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                for (auto it : adj[i])
                {
                    if (vis[it] == true)
                    {
                        flag = true;
                        break;
                    }
                }
            }
        }

        vector<int> ans;
        if (!flag)
        {
            for (int i = 0; i < n; i++)
            {
                if (!vis[i])
                {
                    ans.push_back(i);
                }
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};