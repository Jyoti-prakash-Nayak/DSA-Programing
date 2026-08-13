// Build: O(n)

// Each update: O(log n)

// All queries: O(n + q log n)

// Space: O(n)
class Solution
{
    struct Node
    {
        int len = 0;
        int pref = 0;
        int suff = 0;
        int best = 0;
        char left = 0;
        char right = 0;
    };

    vector<Node> tree;
    string str;

    Node merge(Node a, Node b)
    {
        if (a.len == 0)
            return b;
        if (b.len == 0)
            return a;

        Node res;
        res.len = a.len + b.len;

        res.left = a.left;
        res.right = b.right;

        res.pref = a.pref;
        res.suff = b.suff;
        res.best = max(a.best, b.best);

        if (a.right == b.left)
        {
            res.best = max(res.best, a.suff + b.pref);

            if (a.pref == a.len)
            {
                res.pref = a.len + b.pref;
            }

            if (b.pref == b.len)
            {
                res.suff = a.suff + b.len;
            }
        }

        return res;
    }

    void build(int u, int l, int r)
    {
        if (l == r)
        {
            tree[u] = {1, 1, 1, 1, str[l], str[l]};
            return;
        }

        int mid = (l + r) / 2;

        build(2 * u, l, mid);
        build(2 * u + 1, mid + 1, r);

        tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    }

    void update(int u, int l, int r, int pos, char c)
    {
        if (l == r)
        {
            str[pos] = c;
            tree[u] = {1, 1, 1, 1, c, c};
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
        {
            update(2 * u, l, mid, pos, c);
        }
        else
        {
            update(2 * u + 1, mid + 1, r, pos, c);
        }

        tree[u] = merge(tree[2 * u], tree[2 * u + 1]);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int> &queryIndices)
    {
        str = s;
        int n = s.size();
        tree.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;
        for (int i = 0; i < queryIndices.size(); i++)
        {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};