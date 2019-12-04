#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		dfs(root, 0, res);
		return res;
	}
	void dfs(TreeNode* root, int tempSum, int& res) {
		if (root == NULL) {
			return;
		}
		tempSum = tempSum * 10 + root->val;
		if (root->right == NULL && root->left == NULL) {
			res += tempSum;
			return;
		}
		dfs(root->left, tempSum, res);
		dfs(root->right, tempSum, res);
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	int res = Solution().sumNumbers(&a);
	cout << res << endl;

	return 0;
}