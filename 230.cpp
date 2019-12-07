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
//	int kthSmallest(TreeNode* root, int k) {
//		int cnt = 0;
//		stack<TreeNode*> s;
//		TreeNode* p = root;
//		while (p || !s.empty()) {
//			while (p) {
//				s.push(p);
//				p = p->left;
//			}
//			p = s.top(); s.pop();
//			++cnt;
//			if (cnt == k)	return p->val;
//			p = p->right;
//		}
//		return 0;
//	}
//};

//解法二
class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		return kthSmallestDFS(root, k);
	}
	int kthSmallestDFS(TreeNode* root, int& k) {
		if (!root) return -1;
		int val = kthSmallestDFS(root->left, k);
		if (k == 0) return val;
		if (--k == 0)	return root->val;
		return kthSmallestDFS(root->right, k);
	}
};

int main() {
	TreeNode a(5);
	TreeNode b(3);
	TreeNode c(6);
	TreeNode d(2);
	TreeNode e(4);
	TreeNode f(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	d.left = &f;
	Solution solve;
	int res = solve.kthSmallest(&a, 3);
	cout << res << endl;

	return 0;
}