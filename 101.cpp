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
	bool isSymmetric(TreeNode* root) {
		return isMirror(root, root);
	}
	bool isMirror(TreeNode* t1, TreeNode* t2) {
		if (t1 == NULL && t2 == NULL)	return true;
		if (t1 == NULL || t2 == NULL)	return false;
		return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(2);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(4);
	TreeNode g(3);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.left = &f;
	c.right = &g;
	int res = Solution().isSymmetric(&a);
	cout << res << endl;

	return 0;
}