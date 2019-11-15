#include<vector>
#include<cstdio>
using namespace std;

class Solution {
public:
	int findCircleNum(vector<vector<int>>& M) {
		vector<int> visit(M.size(), 0);
		int count = 0;
		for (int i = 0; i < M.size(); i++) {
			if (visit[i] == 0) {
				DFS_graph(i, M, visit);
				count++;
			}
		}
		return count;
	}

	void DFS_graph(int u, vector<vector<int>>& graph, vector<int>& visit) {
		visit[u] = 1;
		for (int i = 0; i < graph[u].size(); i++) {
			if (visit[i] == 0 && graph[u][i] == 1) {
				DFS_graph(i, graph, visit);
			}
		}
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