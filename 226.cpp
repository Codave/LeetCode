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
	TreeNode* invertTree(TreeNode* root) {
		if (root == NULL) {
			return NULL;
		}
		invertTree(root->left);
		invertTree(root->right);
		swap(root->left, root->right);
		return root;
	}
};

void pre_print(TreeNode* root) {
	if (!root) {
		return;
	}
	cout << root->val << " ";
	pre_print(root->left);
	pre_print(root->right);
}

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
	TreeNode* root = Solution().invertTree(&a);
	pre_print(root);

	return 0;
}