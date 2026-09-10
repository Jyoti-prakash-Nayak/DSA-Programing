/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    pair<int, int> dfs(TreeNode *root, int &count)
    {
        if (root == NULL)
        {
            return {0, 0};
        }

        auto [leftSum, leftCount] = dfs(root->left, count);
        auto [rightSum, rightCount] = dfs(root->right, count);

        int SubtreeSum = leftSum + rightSum + root->val;
        int SubtreeCount = leftCount + rightCount + 1;

        if (SubtreeSum / SubtreeCount == root->val)
        {
            count++;
        }
        return {SubtreeSum, SubtreeCount};
    }
    int averageOfSubtree(TreeNode *root)
    {
        int count = 0;
        dfs(root, count);
        return count;
    }
};