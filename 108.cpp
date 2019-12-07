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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
	TreeNode* helper(vector<int>& nums, int left, int right) {
		if (left > right) return NULL;
		int mid = left + (right - left) / 2;
		TreeNode* cur = new TreeNode(nums[mid]);
		cur->left = helper(nums, left, mid - 1);
		cur->right = helper(nums, mid + 1, right);
		return cur;
	}
};

void preorder_print(TreeNode* root) {
	if (root == NULL) {
		return;
	}
	printf("%d ", root->val);
	preorder_print(root->left);
	preorder_print(root->right);
}

int main() {
	vector<int> nums({ -10,-3,0,5,9 });
	TreeNode* root = Solution().sortedArrayToBST(nums);
	preorder_print(root);

	return 0;
}