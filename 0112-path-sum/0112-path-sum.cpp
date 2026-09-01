class Solution {
public:
    bool bfs(TreeNode* root, int targetSum, int &sum) {
        if(root == nullptr) return false;

        TreeNode* head = root;
        sum += head->val;

        if(head->left == nullptr && head->right == nullptr)
            return sum == targetSum;

        int oldsum = sum;
        bool ok1 = bfs(head->left, targetSum, sum);
        sum = oldsum;

        bool ok2 = bfs(head->right, targetSum, sum);

        return ok1 | ok2;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        bool ok = bfs(root, targetSum, sum);
        return ok;
    }
};