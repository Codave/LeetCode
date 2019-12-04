#include<iostream>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){ }
};

//解法一
//class Solution {
//public:
//	bool isValidBST(TreeNode* root) {
//		TreeNode* p = root;
//		stack <TreeNode*> st;
//		long inorder = LONG_MIN;
//		while (p || !st.empty()) {
//			while (p) {
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top();
//			st.pop();
//			if (p->val <= inorder)	return false;
//			inorder = p->val;
//			p = p->right;
//		}
//		return true;
//	}
//};

//解法二
class Solution {
public:
	bool isValid(TreeNode* cur, long left, long right) {
		if (cur == NULL)	return true;
		else if (cur->val <= left || cur->val >= right)	return false;
		return isValid(cur->left, left, cur->val) && isValid(cur->right, cur->val, right);
	}
	bool isValidBST(TreeNode* root) {
		return isValid(root, LONG_MIN, LONG_MAX);
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
	int res = Solution().isValidBST(&a);
	cout << res << endl;
	return 0;
}