//#include<iostream>
//#include<vector>
//#include<string>
//#include<unordered_map>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
//class Solution {
//public:
//	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//		vector<TreeNode*> res;
//		unordered_map<string, int> m;
//		helper(root, m, res);
//		return res;
//	}
//	string helper(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) {
//		if (!node) return "#";
//		string str = to_string(node->val) + "," + helper(node->left, m, res) + "," + helper(node->right, m, res);
//		if (m[str] == 1) res.push_back(node);
//		++m[str];
//		return str;
//	}
//};
//
//int main() {
//	TreeNode a(1);
//	TreeNode b(2);
//	TreeNode c(3);
//	TreeNode d(4);
//	TreeNode e(2);
//	TreeNode f(4);
//	TreeNode g(2);
//	a.left = &b;
//	a.right = &c;
//	b.left = &d;
//	c.left = &e;
//	c.right = &f;
//	e.left = &f;
//	vector<TreeNode*> res;
//	res = Solution().findDuplicateSubtrees(&a);
//
//	return 0;
//}