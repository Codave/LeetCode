//#include<iostream>
//using namespace std;
//
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
//
////解法一
////class Solution {
////public:
////	TreeNode* deleteNode(TreeNode* root, int key) {
////		TreeNode* cur = root;
////		TreeNode* pre = root;
////		while (cur && cur->val != key) {
////			pre = cur;
////			if (key < cur->val) {
////				cur = cur->left;
////			}
////			else {
////				cur = cur->right;
////			}
////		}
////		if (!cur) {
////			return root;
////		}
////		if (!cur->left && !cur->right) {
////			if (cur == root) {
////				return NULL;
////			}
////			if (pre->left == cur) {
////				pre->left = NULL;
////			}
////			else {
////				pre->right = NULL;
////			}
////		}
////		else if (cur->left && !cur->right) {
////			if (cur == root) {
////				return cur->left;
////			}
////			if (pre->left == cur) {
////				pre->left = cur->left;
////			}
////			else {
////				pre->right = cur->left;
////			}
////		}
////		else if (cur->right && !cur->left) {
////			if (cur == root) {
////				return cur->right;
////			}
////			if (pre->left == cur) {
////				pre->left = cur->right;
////			}
////			else {
////				pre->right = cur->right;
////			}
////		}
////		else {
////			TreeNode* b = cur->left;
////			while (b->right) {
////				b = b->right;
////			}
////			b->right = cur->right->left;
////			cur->right->left = cur->left;
////			if (cur == root) {
////				return cur->right;
////			}
////			if (pre->left == cur) {
////				pre->left = cur->right;
////			}
////			else {
////				pre->right = cur->right;
////			}
////		}
////		return root;
////	}
////};
//
////解法二(todo)
//class Solution
//{
//public:
//	TreeNode* deleteNode(TreeNode* root, int key)
//	{
//		if (root == nullptr) return nullptr;
//		if (key < root->val)
//		{
//			root->left = deleteNode(root->left, key);
//			return root;
//		}
//		else if (key > root->val)
//		{
//			root->right = deleteNode(root->right, key);
//			return root;
//		}
//		else
//		{
//			if (root->left == nullptr)
//			{
//				TreeNode* rootRight = root->right;
//				delete root;
//				return rootRight;
//			}
//			if (root->right == nullptr)
//			{
//				TreeNode* rootLeft = root->left;
//				delete root;
//				return rootLeft;
//			}
//			TreeNode* tmp = minTreeNode(root->right);
//			tmp->right = removeMin(root->right);
//			tmp->left = root->left;
//			//delete root;
//			return tmp;
//		}
//	}
//private:
//	TreeNode* minTreeNode(TreeNode* root)
//	{
//		if (root->left == nullptr) return root;
//		return minTreeNode(root->left);
//	}
//
//	TreeNode* removeMin(TreeNode* root)
//	{
//		if (root->left == nullptr)
//		{
//			TreeNode* rootRight = root->right;
//			return rootRight;
//		}
//		root->left = removeMin(root->left);
//		return root;
//	}
//};
//
//void preorder_print(TreeNode* root) {
//	if (root == NULL) return;
//	cout << root->val << " ";
//	preorder_print(root->right);
//	preorder_print(root->left);
//}
//
//int main() {
//	TreeNode a(4);
//	TreeNode b(2);
//	TreeNode c(8);
//	TreeNode d(1);
//	TreeNode e(3);
//	TreeNode f(6);
//	TreeNode g(10);
//	TreeNode h(5);
//	TreeNode i(7);
//	TreeNode j(9);
//	TreeNode k(11);
//	a.left = &b;
//	a.right = &c;
//	b.left = &d;
//	b.right = &e;
//	c.left = &f;
//	c.right = &g;
//	f.left = &h;
//	f.right = &i;
//	g.left = &j;
//	g.right = &k;
//
//	TreeNode* root = Solution().deleteNode(&a, 8);
//	preorder_print(root);
//
//	return 0;
//}