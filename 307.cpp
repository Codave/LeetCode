#include<cstdio>
#include<vector>
using namespace std;

//解法一
//class NumArray {
//public:
//	NumArray(vector<int> nums) {
//		if (nums.size() == 0) {
//			return;
//		}
//		int n = nums.size() * 4;
//		for (int i = 0; i < n; i++) {
//			_value.push_back(0);
//		}
//		build_segment_tree(_value, nums, 0, 0, nums.size() - 1);
//		_right_end = nums.size() - 1;
//	}
//	void update(int i, int val) {
//		update_segment_tree(_value, 0, 0, _right_end, i, val);
//	}
//	int sumRange(int i, int j) {
//		return sum_range_segment_tree(_value, 0, 0, _right_end, i, j);
//	}
//
//	void update_segment_tree(vector<int>& value, int pos, int left, int right, int index, int new_value) {
//		if (left == right && left == index) {
//			value[pos] = new_value;
//			return;
//		}
//		int mid = (left + right) / 2;
//		if (index <= mid) {
//			update_segment_tree(value, pos * 2 + 1, left, mid, index, new_value);
//		}
//		else {
//			update_segment_tree(value, pos * 2 + 2, mid + 1, right, index, new_value);
//		}
//		value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
//	}
//
//	int sum_range_segment_tree(vector<int>& value, int pos, int left, int right, int qleft, int qright) {
//		if (qleft > right || qright < left) {
//			return 0;
//		}
//		if (qleft <= left && qright >= right) {
//			return value[pos];
//		}
//		int mid = (left + right) / 2;
//		return sum_range_segment_tree(value, pos * 2 + 1, left, mid, qleft, qright) +
//			sum_range_segment_tree(value, pos * 2 + 2, mid + 1, right, qleft, qright);
//	}
//
//	void build_segment_tree(vector<int>& value, vector<int>& nums, int pos, int left, int right) {
//		if (left == right) {
//			value[pos] = nums[left];
//			return;
//		}
//		int mid = (left + right) / 2;
//		build_segment_tree(value, nums, pos * 2 + 1, left, mid);
//		build_segment_tree(value, nums, pos * 2 + 2, mid + 1, right);
//		value[pos] = value[pos * 2 + 1] + value[pos * 2 + 2];
//	}
//private:
//	vector<int> _value;
//	int _right_end;
//};

//解法二

class NumArray {
public:
	NumArray(vector<int>& arr) {
		if (arr.size() > 0) {
			for (auto v : arr) {
				data.push_back(v);
			}
			tree.resize(4 * data.size());
			buildTree(0, 0, data.size() - 1);
		}
	}

	void update(int i, int val) {
		set(0, 0, data.size() - 1, i, val);
	}

	int sumRange(int i, int j) {
		if (data.size() == 0)	return 0;
		return query(0, 0, data.size() - 1, i, j);
	}

private:
	vector<int> tree;
	vector<int> data;
	int leftchild(int index) {
		return index * 2 + 1;
	}
	int rightchild(int index) {
		return index * 2 + 2;
	}
	void set(int treeIndex, int l, int r, int index, int new_value) {
		if (l == r) {
			tree[treeIndex] = new_value;
			return;
		}
		int mid = l + (r - l) / 2;
		int leftTreeIndex = leftchild(treeIndex);
		int rightTreeIndex = rightchild(treeIndex);
		if (index >= mid + 1) {
			set(rightTreeIndex, mid + 1, r, index, new_value);
		}
		else {
			set(leftTreeIndex, l, mid, index, new_value);
		}
		tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
	}
	int query(int treeIndex, int l, int r, int queryL, int queryR) {
		if (l == queryL && r == queryR) {
			return tree[treeIndex];
		}
		int mid = l + (r - l) / 2;
		int leftTreeIndex = leftchild(treeIndex);
		int rightTreeIndex = rightchild(treeIndex);
		if (queryL >= mid + 1) {
			return query(rightTreeIndex, mid + 1, r, queryL, queryR);
		}
		else if (queryR <= mid) {
			return query(leftTreeIndex, l, mid, queryL, queryR);
		}
		int leftresult = query(leftTreeIndex, l, mid, queryL, mid);
		int rightresult = query(rightTreeIndex, mid + 1, r, mid + 1, queryR);
		return leftresult + rightresult;
	}
	void buildTree(int treeIndex, int l, int r) {
		if (l == r) {
			tree[treeIndex] = data[l];
			return;
		}
		int leftTreeIndex = leftchild(treeIndex);
		int rightTreeIndex = rightchild(treeIndex);
		int mid = l + (r - l) / 2;
		buildTree(leftTreeIndex, l, mid);
		buildTree(rightTreeIndex, mid + 1, r);
		tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
	}
};

//void print_segment_tree(vector<int>& value, int pos, int left, int right, int layer) {
//	for (int i = 0; i < layer; i++) {
//		printf("---");
//	}
//	printf("[%d %d][%d]:%d\n",left, right, pos, value[pos]);
//	if (left == right) {
//		return;
//	}
//	int mid = (left + right) / 2;
//	print_segment_tree(value, pos * 2 + 1, left, mid, layer + 1);
//	print_segment_tree(value, pos * 2 + 2, mid + 1, right, layer + 1);
//}

//int main() {
//
//	vector<int> nums;
//	for (int i = 0; i < 6; i++) {
//		nums.push_back(i);
//	}
//	vector<int> value;
//	for (int i = 0; i < 24; i++) {
//		value.push_back(0);
//	}
//	build_segment_tree(value, nums, 0, 0, nums.size() - 1);
//	printf("segment_tree:\n");
//	print_segment_tree(value, 0, 0, nums.size() - 1, 0);
//	int sum_range = sum_range_segment_tree(value, 0, 0, nums.size() - 1, 2, 4);
//	printf("sum_range[2,5]=%d\n", sum_range);
//	update_segment_tree(value, 0, 0, nums.size() - 1, 2, 10);
//	printf("segment_tree:\n");
//	print_segment_tree(value, 0, 0, nums.size() - 1, 0);
//
//	return 0;
//}

int main() {
	vector<int> nums = { 1,3,5 };
	NumArray num_array(nums);
	printf("%d\n", num_array.sumRange(0, 2));
	num_array.update(1, 2);
	printf("%d\n", num_array.sumRange(0, 2));

	return 0;
}