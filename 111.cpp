#include<iostream>
#include<vector>
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
	int minDepth(TreeNode* root) {
		int result = 0;
		if (root == NULL) {
			return result;
		}
		else {
			if (root->left && root->right) {
				result = min(minDepth(root->left), minDepth(root->right)) + 1;
			}
			else if (!root->left) {
				result = minDepth(root->right) + 1;
			}
			else if (!root->right) {
				result = minDepth(root->left) + 1;
			}
		}
		return result;
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
	int res = Solution().minDepth(&a);
	cout << res << endl;

	return 0;
}