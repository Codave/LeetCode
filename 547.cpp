#include<vector>
#include<cstdio>
using namespace std;

//解法一
//class Solution {
//public:
//	int findCircleNum(vector<vector<int>>& M) {
//		vector<int> visit(M.size(), 0);
//		int count = 0;
//		for (int i = 0; i < M.size(); i++) {
//			if (visit[i] == 0) {
//				DFS_graph(i, M, visit);
//				count++;
//			}
//		}
//		return count;
//	}
//
//	void DFS_graph(int u, vector<vector<int>>& graph, vector<int>& visit) {
//		visit[u] = 1;
//		for (int i = 0; i < graph[u].size(); i++) {
//			if (visit[i] == 0 && graph[u][i] == 1) {
//				DFS_graph(i, graph, visit);
//			}
//		}
//	}
//
//};

//解法二
class DisjointSet {
public:
	DisjointSet(int n) {
		for (int i = 0; i < n; i++) {
			father.push_back(i);
			_size.push_back(1);
		}
		_count = n;
	}
	int find(int x) {
		while (x != father[x]) {
			//father[x] = father[father[x]];
			x = father[x];
		}
		return x;
	}
	void union_(int a, int b) {
		int faA = find(a);
		int faB = find(b);
		if (faA == faB) {
			return;
		}
		if (_size[faA] < _size[faB]) {
			father[faA] = faB;
			_size[faB] += _size[faA];
		}
		else {
			father[faB] = faA;
			_size[faA] = _size[faB];
		}
		_count--;
	}
	int count() {
		return _count;
	}
private:
	vector<int> father;
	vector<int> _size;
	int _count;
};

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		DisjointSet disjoint_set(M.size());
		for (int i = 0; i < M.size(); i++) {
			for (int j = i + 1; j < M.size(); j++) {
				if (M[i][j]) {
					disjoint_set.union_(i, j);
				}
			}
		}
		return disjoint_set.count();
	}
};

int main() {
	int test[][3] = { {1,1,0},{1,1,0},{0,0,1} };
	vector<vector<int>> M(3, vector<int>(3, 0));
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			M[i][j] = test[i][j];
		}
	}
	Solution solve;
	printf("%d\n", solve.findCircleNum(M));
	
	return 0;
}