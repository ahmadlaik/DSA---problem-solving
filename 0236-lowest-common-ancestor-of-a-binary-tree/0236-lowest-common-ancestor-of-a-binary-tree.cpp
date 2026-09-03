/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    bool findPath(TreeNode* root, TreeNode* p, vector<TreeNode*>& path) {

        if (root == NULL) {
            return false;
        }

        path.push_back(root);

        if (root == p) {
            return true;
        }

        bool isLeft = findPath(root->left, p, path);
        bool isRight = findPath(root->right, p, path);

        if (isLeft || isRight) {
            return true;
        }

        path.pop_back();

        return false;
    }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        vector<TreeNode*> path1;
        vector<TreeNode*> path2;

        findPath(root, p, path1);
        findPath(root, q, path2);

        TreeNode* lca = NULL;

        int i = 0;

        while (i < path1.size() && i < path2.size()) {

            if (path1[i] != path2[i]) {
                break;
            }

            lca = path1[i];
            i++;
        }

        return lca;
    }
};