#include<iostream>
#include<vector>
using namespace std;

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
		int rightresult = query(rightTreeIndex, mid + 1, r, mid + 1,queryR);
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
		buildTree(rightTreeIndex, mid+1, r);
		tree[treeIndex] = tree[leftTreeIndex] + tree[rightTreeIndex];
	}
};

int main() {


	return 0;
}