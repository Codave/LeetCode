#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};
class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
	}
	TreeNode* build(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
		if (pLeft > pRight || iLeft > iRight) return NULL;
		int i = 0;
		for (i = iLeft; i <= iRight; ++i) {
			if (preorder[pLeft] == inorder[i]) break;
		}
		TreeNode* cur = new TreeNode(preorder[pLeft]);
		cur->left = build(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
		cur->right = build(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
		return cur;
	}
};

int main() {

	vector<int> pre = { 3,9,20,15,7 };
	vector<int> in = { 9,3,15,20,7 };
	TreeNode* root = Solution().buildTree(pre, in);


	return 0;
}