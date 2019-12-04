#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
	int pathSum(TreeNode* root, int sum) {
		if (root == NULL)	return 0;
		int res = findPath(root, sum);
		res += pathSum(root->left, sum);
		res += pathSum(root->right, sum);
		return res;
	}
	int findPath(TreeNode* node, int num) {
		if (node == NULL) {
			return 0;
		}
		int res = 0;
		if (node->val == num) {
			res += 1;
		}
		res += findPath(node->left, num - node->val);
		res += findPath(node->right, num - node->val);
		return res;
	}
};

int main() {
	TreeNode a(10);
	TreeNode b(5);
	TreeNode c(-3);
	TreeNode d(3);
	TreeNode e(2);
	TreeNode f(11);
	TreeNode g(3);
	TreeNode h(-2);
	TreeNode i(1);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	d.left = &g;
	d.right = &h;
	e.right = &i;
	int res = Solution().pathSum(&a, 8);
	cout << res << endl;

	return 0;
}