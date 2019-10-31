#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){ }
};

class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		vector<int> view;	//按层遍历的最后一个节点
		queue<pair<TreeNode*, int>> Q;	//广度优先搜索队列<节点，层数>

		if (root) {		//节点非空时，将<root,0>入队
			Q.push(make_pair(root, 0));
		}

		while (!Q.empty()) {
			TreeNode* node = Q.front().first;//搜索节点
			int depth = Q.front().second;	//待搜索节点的层数
			Q.pop();
			if (view.size() == depth) {
				view.push_back(node->val);
			}
			else {
				view[depth] = node->val;
			}
			if (node->left) {
				Q.push(make_pair(node->left, depth + 1));
			}
			if (node->right) {
				Q.push(make_pair(node->right, depth + 1));
			}
		}
		return view;
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(5);
	TreeNode d(3);
	TreeNode e(4);
	TreeNode f(6);
	a.left = &b;
	a.right = &c;
	b.left = &d;
	b.right = &e;
	c.right = &f;
	Solution solve;
	vector<int> result = solve.rightSideView(&a);
	for (int i = 0; i < result.size(); i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}