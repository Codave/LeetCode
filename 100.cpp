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
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == NULL && q == NULL)	return true;
		if (p && q && p->val == q->val) {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}
		else {
			return false;
		}
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.left = &b;
	a.right = &c;

	TreeNode d(1);
	TreeNode e(2);
	TreeNode f(3);
	d.left = &e;
	d.right = &f;

	int res = Solution().isSameTree(&a, &d);
	cout << res << endl;

	return 0;
}