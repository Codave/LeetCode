#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

//解法一（迭代）[栈模拟递归]
//struct Command {
//	string s;	//go,print
//	TreeNode* node;
//	Command(string s, TreeNode* node) :s(s), node(node) { }
//};
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> res;
//		if (!root) {
//			return res;
//		}
//		stack<Command> stack;
//		stack.push(Command("go", root));
//		while (!stack.empty()) {
//			Command command = stack.top();
//			stack.pop();
//			if (command.s == "print") {
//				res.push_back(command.node->val);
//			}
//			else {
//				if (command.node->right) {
//					stack.push(Command("go", command.node->right));
//				}
//				if (command.node->left) {
//					stack.push(Command("go", command.node->left));
//				}
//				stack.push(Command("print", command.node));
//			}
//		}
//		return res;
//	}
//};

//解法二（递归）
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> ret;
//		pre_travel(root, ret);
//		return ret;
//	}
//	void pre_travel(TreeNode* root, vector<int>& ret) {
//		if (root) {
//			ret.push_back(root->val);
//			pre_travel(root->left, ret);
//			pre_travel(root->right, ret);
//		}
//	}
//};

//解法三（迭代）[栈模拟递归]
//class Solution {
//public:
//	vector<int> preorderTraversal(TreeNode* root) {
//		vector<int> ret;
//		if (!root)	return ret;
//		stack<TreeNode*> st;
//		TreeNode* p = root;
//		while (p || !st.empty()) {
//			while (p) {
//				ret.push_back(p->val);
//				st.push(p);
//				p = p->left;
//			}
//			p = st.top();
//			st.pop();
//			p = p->right;
//		}
//		return ret;
//	}
//};

//解法四（迭代）[栈模拟递归]
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root)	return ret;
		stack<TreeNode*> st;
		st.push(root);
		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();
			ret.push_back(node->val);
			if (node->right) {
				st.push(node->right);	//先入右边
			}
			if (node->left) {
				st.push(node->left);	//后入左边
			}
		}
		return ret;
	}
};

int main() {
	TreeNode a(1);
	TreeNode b(2);
	TreeNode c(3);
	a.right = &b;
	b.left = &c;
	vector<int> res = Solution().preorderTraversal(&a);
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}