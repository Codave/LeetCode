#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int ans = INT_MIN;
	int maxPathSum(TreeNode* root) {
		dfs(root);
		return ans;
	}
	int dfs(TreeNode* root) {
		if (!root) {
			return 0;
		}
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, root->val + left + right);
		return max(0, root->val + max(left, right)); //向上返回时只能选择一条路径，左子树或者右子树
	}
};

int main() {
	TreeNode a(-10);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;
	int res = Solution().maxPathSum(&a);
	cout << res << endl;
	return 0;
}