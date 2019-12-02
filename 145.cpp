#include<iostream>
#include<string>
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
//	vector<int> postorderTraversal(TreeNode* root) {
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
//				stack.push(Command("print", command.node));
//				if (command.node->right) {
//					stack.push(Command("go", command.node->right));
//				}
//				if (command.node->left) {
//					stack.push(Command("go", command.node->left));
//				}
//			}
//		}
//		return res;
//	}
//};

//解法二（递归）
//class Solution {
//public:
//	vector<int> postorderTraversal(TreeNode* root) {
//		vector<int> ret;
//		pre_travel(root, ret);
//		return ret;
//	}
//	void pre_travel(TreeNode* root, vector<int>& ret) {
//		if (root) {
//			pre_travel(root->left, ret);
//			pre_travel(root->right, ret);
//			ret.push_back(root->val);
//		}
//	}
//};

//解法三（迭代）[栈模拟递归]
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> ret;
		if (!root)	return ret;
		stack<TreeNode*> st;
		TreeNode* p = root;
		TreeNode* lastVisit = NULL;
		while (p || !st.empty()) {
			if (p) {
				st.push(p);
				p = p->left;
			}
			else {
				TreeNode* v = st.top();
				//
				if (v->right && v->right != lastVisit) {
					p = v->right;
				}
				else {
					ret.push_back(v->val);
					lastVisit = v;
					st.pop();
				}
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
	vector<int> res = Solution().postorderTraversal(&a);
	for (auto iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}