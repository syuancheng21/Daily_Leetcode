#include "type.h"
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> ans;
    levelOrderHelp(ans, root, 0);
    return ans;
  }

  void levelOrderHelp(vector<vector<int>> &ans, TreeNode *root, int len) {
    if (root == nullptr) {
      return;
    }
    if (len >= ans.size()) {
      ans.push_back({});
    }
    ans[len].push_back(root->val);
    levelOrderHelp(ans, root->left, len + 1);
    levelOrderHelp(ans, root->right, len + 1);
  }
};