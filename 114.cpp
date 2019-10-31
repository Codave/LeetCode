//#include<cstdio>
//#include<vector>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) :val(x), left(NULL), right(NULL) { }
//};
//
////解法一
////class Solution {
////public:
////	void flatten(TreeNode* root) {
////		vector<TreeNode*> node_vec;
////		preorder(root, node_vec);
////		for (int i = 1; i < node_vec.size(); i++) {
////			node_vec[i-1]->left = NULL;
////			node_vec[i-1]->right = node_vec[i];
////		}
////	}
////private:
////	void preorder(TreeNode* node, vector<TreeNode*>& node_vec) {
////		if (!node) {
////			return;
////		}
////		node_vec.push_back(node);
////		preorder(node->left, node_vec);
////		preorder(node->right, node_vec);
////	}
////};
//
////解法二
//class Solution {
//public:
//	void flatten(TreeNode* root) {
//		TreeNode* last = NULL;
//		preorder(root, last);
//	}
//private:
//	void preorder(TreeNode* node, TreeNode* &last) {
//		if (!node) {
//			return;
//		}
//		if (!node->left && !node->right) {
//			last = node;
//			return;
//		}
//		TreeNode* left = node->left;
//		TreeNode* right = node->right;
//		TreeNode* left_last = NULL;
//		TreeNode* right_last = NULL;
//		if (left) {
//			preorder(left, left_last);
//			node->left = NULL;
//			node->right = left;
//			last = left_last;
//		}
//		if (right) {
//			preorder(right, right_last);
//			if (left_last) {
//				left_last->right = right;
//			}
//			last = right_last;
//		}
//	}
//};
//
//int main() {
//
//	TreeNode a(1);
//	TreeNode b(2);
//	TreeNode c(5);
//	TreeNode d(3);
//	TreeNode e(4);
//	TreeNode f(6);
//	a.left = &b;
//	a.right = &c;
//	b.left = &d;
//	b.right = &e;
//	c.right = &f;
//
//	Solution solve;
//	solve.flatten(&a);
//	TreeNode* head = &a;
//	while (head) {
//		if (head->left) {
//			printf("Error\n");
//		}
//		printf("%d ", head->val);
//		head = head->right;
//	}
//	printf("\n");
//	return 0;
//}