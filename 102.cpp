#include<iostream>
#include<vector>
#include<queue>
#include<utility>
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
//	vector<vector<int>> levelOrder(TreeNode* root) {
//		vector<vector<int>> res;
//		if (root == NULL) {
//			return res;
//		}
//		queue<pair<TreeNode*, int>> q;
//		q.push(make_pair(root, 0));
//		while (!q.empty()) {
//			TreeNode* node = q.front().first;
//			int level = q.front().second;
//			q.pop();
//			if (level == res.size()) {
//				res.push_back(vector<int>());
//			}
//			res[level].push_back(node->val);
//			if (node->left) {
//				q.push(make_pair(node->left, level + 1));
//			}
//			if (node->right) {
//				q.push(make_pair(node->right, level + 1));
//			}
//		}
//		return res;
//	}
//};

//解法二
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q{ {root} };
		while (!q.empty()) {
			vector<int> oneLevel;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* t = q.front(); q.pop();
				oneLevel.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			res.push_back(oneLevel);
		}
		return res;
	}
};

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
	vector<vector<int>> res = Solution().levelOrder(&a);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}