class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        set<int> st(nums.begin(), nums.end());
        int start = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());

        vector<int> res;
        for (int i = start + 1; i < end; i++)
        {
            if (st.find(i) == st.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};