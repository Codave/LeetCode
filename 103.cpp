#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

//解法一
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode*> q;
		if (!root) return res;
		q.push(root);
		bool even = false;
		while (!q.empty()) {
			queue<TreeNode*> temp;
			vector<int> temp_res;
			while (!q.empty()) {
				TreeNode* node = q.front();
				q.pop();
				temp_res.push_back(node->val);
				if (node->left) temp.push(node->left);
				if (node->right) temp.push(node->right);
			}
			q = temp;
			if (even) {
				vector<int> reverse_t(temp_res.rbegin(), temp_res.rend());
				res.push_back(reverse_t);
				even = false;
			}
			else {
				res.push_back(temp_res);
				even = true;
			}
		}
		return res;
	}
};

//解法二
class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* pRoot) {
		if (!pRoot) return {};
		vector<vector<int>> res;
		queue<TreeNode*> q{ {pRoot} };
		bool flag = false;
		while (!q.empty()) {
			vector<int> oneLevel;
			for (int i = q.size(); i > 0; --i) {
				TreeNode* t = q.front();
				q.pop();
				oneLevel.push_back(t->val);
				if (t->left) q.push(t->left);
				if (t->right) q.push(t->right);
			}
			if (flag) {
				reverse(oneLevel.begin(), oneLevel.end());
			}
			res.push_back(oneLevel);
			flag = !flag;
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
	vector<vector<int>> res = Solution().zigzagLevelOrder(&a);
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		for (auto it = (*iter).begin(); it != (*iter).end(); it++) {
			cout << *it << " ";
		}
		cout << endl;
	}

	return 0;
}