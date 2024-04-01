//
// Created by clf on 2023/10/18.
//

#ifndef LEETCODECPP_LC543_H
#define LEETCODECPP_LC543_H
#include <math.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int lh = depth(root->left);
        int rh = depth(root->right);
        int h = lh + rh + 2;
        if (lh == 0) h--;
        if (rh == 0) h--;
        return h;
    }

    int depth(TreeNode* root) {
        if (root == nullptr) return 0;
        int lh = 0;
        int rh = 0;
        lh = depth(root->left)+1;
        rh = depth(root->right)+1;
        return max(lh, rh);
    }
};
#endif //LEETCODECPP_LC543_H
