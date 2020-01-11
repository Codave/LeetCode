#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

//解法一
//class Solution {
//public:
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
//	}
//	TreeNode* build(vector<int>& preorder, int pLeft, int pRight, vector<int>& inorder, int iLeft, int iRight) {
//		if (pLeft > pRight || iLeft > iRight) return NULL;
//		int i = 0;
//		for (i = iLeft; i <= iRight; ++i) {
//			if (preorder[pLeft] == inorder[i]) break;
//		}
//		TreeNode* cur = new TreeNode(preorder[pLeft]);
//		cur->left = build(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
//		cur->right = build(preorder, pLeft + i - iLeft + 1, pRight, inorder, i + 1, iRight);
//		return cur;
//	}
//};

//解法二
class Solution {
public:
	unordered_map<int, int> pos;
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		int n = preorder.size();
		for (int i = 0; i < n; i++) {
			pos[inorder[i]] = i;
		}
		return dfs(preorder, inorder, 0, n - 1, 0, n - 1);
	}
	TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int pl, int pr, int il, int ir) {
		if (pl > pr) return NULL;
		int val = preorder[pl];
		int k = pos[val];
		int len = k - il;
		auto root = new TreeNode(val);
		root->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
		root->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);
		return root;
	}
};

int main() {

	vector<int> pre = { 3,9,8,10,20,15,7 };
	vector<int> in = { 8,9,10,3,15,20,7 };
	TreeNode* root = Solution().buildTree(pre, in);


	return 0;
}