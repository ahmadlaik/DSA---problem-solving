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

    bool isIdentical(TreeNode* root, TreeNode* subRoot) {

        if (root == NULL && subRoot == NULL) {
            return true;
        }

        if (root == NULL || subRoot == NULL) {
            return false;
        }

        if (root->val != subRoot->val) {
            return false;
        }

        return isIdentical(root->left, subRoot->left) &&
               isIdentical(root->right, subRoot->right);
    }


    bool ISS(TreeNode* root, TreeNode* subRoot) {

        if (root == NULL) {
            return false;
        }

        // If values match, check whether the complete trees are identical
        if (root->val == subRoot->val) {
            if (isIdentical(root, subRoot)) {
                return true;
            }
        }

        // Search in left and right subtree
        return ISS(root->left, subRoot) ||
               ISS(root->right, subRoot);
    }


    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (subRoot == NULL) {
            return true;
        }

        if (root == NULL) {
            return false;
        }

        return ISS(root, subRoot);
    }
};