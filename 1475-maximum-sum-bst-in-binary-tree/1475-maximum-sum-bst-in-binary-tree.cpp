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
class Solution {
public:
int maxSum = 0;

    int dfs(TreeNode* node, int& minVal, int& maxVal, bool& isBST) {
        if (!node) {
            isBST = true;
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return 0;
        }

        int leftMin, leftMax, rightMin, rightMax;
        bool leftBST, rightBST;

        int leftSum = dfs(node->left, leftMin, leftMax, leftBST);
        int rightSum = dfs(node->right, rightMin, rightMax, rightBST);

        if (leftBST && rightBST && node->val > leftMax && node->val < rightMin) {
            isBST = true;
            minVal = std::min(node->val, leftMin);
            maxVal = std::max(node->val, rightMax);
            int total = node->val + leftSum + rightSum;
            maxSum = std::max(maxSum, total);
            return total;
        }

        isBST = false;
        return 0;
    }
    int maxSumBST(TreeNode* root) {
        int minVal, maxVal;
        bool isBST;
        dfs(root, minVal, maxVal, isBST);
        return maxSum;
    }
};