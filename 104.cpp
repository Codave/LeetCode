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
	int maxDepth(TreeNode* root) {
		if (root == NULL) {
			return 0;
		}
		int leftMaxDepth = maxDepth(root->left);
		int rightMaxDepth = maxDepth(root->right);
		return max(leftMaxDepth, rightMaxDepth) + 1;
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
	int res = Solution().maxDepth(&a);
	cout << res << endl;

	return 0;
}