#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	bool isBalanced(TreeNode* root) {
		if (root == NULL) return true;
		return abs(depth(root->right) - depth(root->left)) < 2 && isBalanced(root->right) && isBalanced(root->left);
	}
	int depth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		return 1 + max(depth(root->right), depth(root->left));
	}
};

int main() {
	TreeNode a(3);
	TreeNode b(9);
	TreeNode c(20);
	TreeNode d(15);
	TreeNode e(7);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;
	int res = Solution().isBalanced(&a);
	cout << res << endl;

	return 0;
}