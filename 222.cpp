#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	int countNodes(TreeNode* root) {
		if (root == NULL) return 0;
		return 1+countNodes(root->left) + countNodes(root->right);
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;
	int res = Solution().countNodes(&a);
	cout << res << endl;

	return 0;
}