#include<cstdio>
#include<vector>
#include<string>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<int> countSmaller(vector<int>& nums) {
//		vector<pair<int, int>> vec;
//		vector<int> count;
//		for (int i = 0; i < nums.size(); i++) {
//			vec.push_back(make_pair(nums[i], i));
//			count.push_back(0);
//		}
//		merge_sort(vec, count);
//		return count;
//	}
//	void merge_sort_two_vec(vector<pair<int, int>>& sub_vec1, vector<pair<int, int>>& sub_vec2, vector<pair<int, int>>& vec, vector<int>& count) {
//		int i = 0;
//		int j = 0;
//		while (i < sub_vec1.size() && j < sub_vec2.size()) {
//			if (sub_vec1[i].first <= sub_vec2[j].first) {
//				count[sub_vec1[i].second] += j;
//				vec.push_back(sub_vec1[i]);
//				i++;
//			}
//			else {
//				vec.push_back(sub_vec2[j]);
//				j++;
//			}
//		}
//		for (; i < sub_vec1.size(); i++) {
//			count[sub_vec1[i].second] += j;
//			vec.push_back(sub_vec1[i]);
//		}
//		for (; j < sub_vec2.size(); j++) {
//			vec.push_back(sub_vec2[j]);
//		}
//	}
//	void merge_sort(vector<pair<int, int>>& vec, vector<int>& count) {
//		if (vec.size() < 2) {
//			return;
//		}
//		int mid = vec.size() / 2;
//		vector<pair<int, int>> sub_vec1;
//		vector<pair<int, int>> sub_vec2;
//		for (int i = 0; i < mid; i++) {
//			sub_vec1.push_back(vec[i]);
//		}
//		for (int i = mid; i < vec.size(); i++) {
//			sub_vec2.push_back(vec[i]);
//		}
//		merge_sort(sub_vec1, count);
//		merge_sort(sub_vec2, count);
//		vec.clear();
//		merge_sort_two_vec(sub_vec1, sub_vec2, vec, count);
//	}
//};

//解法二
struct BSTNode {
	int val;
	int count;
	BSTNode* left;
	BSTNode* right;
	BSTNode(int x) :val(x), count(0), left(NULL), right(NULL){ }
};

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int> result;	//最终逆序数数组
		vector<BSTNode*> node_vec;	//创建的二叉查找树节点池
		vector<int> count;
		for (int i = nums.size() - 1; i >= 0; i--) {
			node_vec.push_back(new BSTNode(nums[i]));	//按照从后向前的顺序创建二叉查找树节点
		}
		count.push_back(0);
		for (int i = 1; i < node_vec.size(); i++) {
			int count_small = 0;
			BST_insert(node_vec[0], node_vec[i], count_small);
			count.push_back(count_small);
		}
		for (int i = node_vec.size() - 1; i >= 0; i--) {
			delete node_vec[i];
			result.push_back(count[i]);
		}
		return result;
	}
private:
	void BST_insert(BSTNode* node, BSTNode* insert_node, int& count_small) {
		if (insert_node->val <= node->val) {
			node->count++;
			if (node->left) {
				BST_insert(node->left, insert_node, count_small);
			}
			else {
				node->left = insert_node;
			}
		}
		else {
			count_small += node->count + 1;
			if (node->right) {
				BST_insert(node->right, insert_node, count_small);
			}
			else {
				node->right = insert_node;
			}
		}
	}
};

int main() {
	int test[] = { 5,-7,9,1,3,5,-2,1 };
	vector<int> nums;
	for (int i = 0; i < 8; i++) {
		nums.push_back(test[i]);
	}
	Solution solve;
	vector<int> result = solve.countSmaller(nums);
	for (int i = 0; i < result.size(); i++) {
		printf("[%d]", result[i]);
	}
	printf("\n");

	return 0;
}
