#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> inorderTraversal(TreeNode* root) {
    if (root == NULL) {
        return vector<int>();
    }
    stack<TreeNode*> S;
    vector<int> v;
    S.push(root);
    root = root->left;
    while(!S.empty()) {
        while(root) {
            S.push(root);
            root = root->left;
        }
        root = S.top();
        S.pop();
        v.push_back(root->val);
        root = root->right;
        if (root) {
            S.push(root);
            root = root ->left;
        }
    }
    return v;
}
