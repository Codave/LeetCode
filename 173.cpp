#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){ }
};

class BSTIterator {
public:
	stack<TreeNode*> s;
	BSTIterator(TreeNode* root) {
		while (root) {
			s.push(root);
			root = root->left;
		}
	}
	int next() {
		auto p = s.top();
		s.pop();
		int res = p->val;
		p = p->right;
		while (p) {
			s.push(p);
			p = p->left;
		}
		return res;
	}
	bool hasNext() {
		return !s.empty(); 
	}
};