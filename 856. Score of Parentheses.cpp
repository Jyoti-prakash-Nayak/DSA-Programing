class Solution
{
public:
    int scoreOfParentheses(string s)
    {
        int n = s.size();
        stack<int> st;
        int res = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                st.push(res);
                res = 0;
            }
            else
            {
                res = st.top() + max(2 * res, 1);
                st.pop();
            }
        }
        return res;
    }
};