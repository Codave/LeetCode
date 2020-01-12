#include<iostream>
#include<string>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Codec {
public:

	// Encodes a tree to a single string.
	string serialize(TreeNode* root) {
		string res;
		dfs1(root, res);
		return res;
	}
	void dfs1(TreeNode* root, string& res) {
		if (!root) {
			res += "#,";
			return;
		}
		res += to_string(root->val) + ',';
		dfs1(root->left, res);
		dfs1(root->right, res);
	}
	// Decodes your encoded data to tree.
	TreeNode* deserialize(string data) {
		int u = 0;
		return dfs2(data, u);
	}
	TreeNode* dfs2(string& data, int& u) {
		if (data[u] == '#') {
			u += 2;
			return NULL;
		}
		int t = 0;
		bool is_minus = false;
		if (data[u] == '-') {
			is_minus = true;
			u++;
		}
		while (data[u] != ',') {
			t = t * 10 + data[u] - '0';
			u++;
		}
		u++;
		if (is_minus) t = -t;
		auto root = new TreeNode(t);
		root->left = dfs2(data, u);
		root->right = dfs2(data, u);
		return root;
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	TreeNode d(4);
	TreeNode e(5);
	a.left = &b;
	a.right = &c;
	c.left = &d;
	c.right = &e;
	string str = Codec().serialize(&a);
	Codec().deserialize(str);

	return 0;
}