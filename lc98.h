//
// Created by clf on 2023/10/10.
//

#ifndef LEETCODECPP_LC98_H
#define LEETCODECPP_LC98_H
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class lc98 {
public:
    vector<int> v;
    bool isValidBST(TreeNode* root) {
        inorder(root);
        int pre = v[0];
        for (int i = 1; i < v.size(); i ++) {
            if (v[i] <= pre) {
                return false;
            }
            pre = v[i];
        }
        return true;
    }

    void inorder(TreeNode* root) {
        if (root->left != nullptr) {
            inorder(root->left);
        }
        v.emplace_back(root->val);
        if (root->right != nullptr) {
            inorder(root->right);
        }
    }
};

#endif //LEETCODECPP_LC98_H
