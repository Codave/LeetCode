#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};

//解法一
//class Solution {
//public:
//	bool isSymmetric(TreeNode* root) {
//		return isMirror(root, root);
//	}
//	bool isMirror(TreeNode* t1, TreeNode* t2) {
//		if (t1 == NULL && t2 == NULL)	return true;
//		if (t1 == NULL || t2 == NULL)	return false;
//		return (t1->val == t2->val) && isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right);
//	}
//};

//解法二
//class Solution {
//public:
//	bool isSymmetric(TreeNode* root) {
//		if (!root) return true;
//		return dfs(root->left, root->right);
//	}
//	bool dfs(TreeNode* p, TreeNode* q) {
//		if (!p || !q) return !p && !q;
//		return (p->val == q->val) && (p->left, q->right) && (p->right, q->left);
//	}
//};

//解法三
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		stack<TreeNode*> left, right;
		TreeNode* l = root->left;
		TreeNode* r = root->right;
		while (l || r || !left.empty() || !right.empty()) {
			while (l && r) {
				left.push(l);
				right.push(r);
				l = l->left;
				r = r->right;
			}
			if (l || r) return false;
			l = left.top(), left.pop();
			r = right.top(), right.pop();
			if (l->val != r->val) return false;
			l = l->right;
			r = r->left;
		}
		return true;
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