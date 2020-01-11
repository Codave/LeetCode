#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	int ans = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		dfs(root);
		return ans;
	}
	int dfs(TreeNode* root) {
		if (!root) return 0;
		auto left = dfs(root->left);
		auto right = dfs(root->right);
		ans = max(ans, left + right);
		return max(left + 1, right + 1);
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	int res = Solution().diameterOfBinaryTree(&a);
	cout << res << endl;

	return 0;
}