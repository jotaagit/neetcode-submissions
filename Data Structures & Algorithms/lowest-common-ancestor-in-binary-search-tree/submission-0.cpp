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
    bool search(TreeNode* p, int val, std::vector<TreeNode*>& path) {
        if (!p) return false;
        path.push_back(p);
        if (p->val == val) return true;
        if (search(p->left, val, path) || search(p->right, val, path)) {
            return true;
        }
        path.pop_back();
        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        std::vector<TreeNode*> pathP;
        std::vector<TreeNode*> pathQ;
        search(root, p->val, pathP);
        search(root, q->val, pathQ);
        int i = 0;
        while (i < pathP.size() && i < pathQ.size()) {
            if (pathP[i]->val != pathQ[i]->val) {
                break;
            }
            i++;
        }
        return pathP[i - 1];
    }
};
