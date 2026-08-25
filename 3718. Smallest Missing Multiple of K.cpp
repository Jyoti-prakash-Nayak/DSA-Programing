class Solution
{
public:
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> st(nums.begin(), nums.end());

        int ans = k;
        int prod = 1;
        bool flag = true;
        while (prod && flag == true)
        {
            int val = k * prod;
            if (st.find(val) == st.end())
            {
                ans = val;
                flag = false;
                break;
            }
            prod++;
        }
        return ans;
    }
};