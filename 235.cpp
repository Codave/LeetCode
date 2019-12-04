#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == NULL) {
			return NULL;
		}
		if (p->val < root->val && q->val < root->val) {
			return lowestCommonAncestor(root->left, p, q);
		}
		if (p->val > root->val&& q->val > root->val) {
			return lowestCommonAncestor(root->right, p, q);
		}
		return root;
	}
};

int main() {
	TreeNode a(6);
	TreeNode b(2);
	TreeNode c(8);
	TreeNode d(0);
	TreeNode e(4);
	TreeNode f(7);
	TreeNode g(9);
	TreeNode h(3);
	TreeNode i(5);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	e.left = &h;
	e.right = &i;
	c.left = &f;
	c.right = &g;
	TreeNode* ancestor = Solution().lowestCommonAncestor(&a, &b, &c);
	cout << ancestor->val << endl;
	return 0;
}