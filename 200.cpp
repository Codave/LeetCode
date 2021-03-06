#include<vector>
#include<cstdio>
#include<queue>
#include<utility>
using namespace std;

//解法一
//class Solution {
//public:
//	int numIslands(vector<vector<char>>& grid) {
//		int island_num = 0;
//		vector<vector<int>> mark;
//		for (int i = 0; i < grid.size(); i++) {
//			mark.push_back(vector<int>());
//			for (int j = 0; j < grid[i].size(); j++) {
//				mark[i].push_back(0);
//			}
//		}
//		for (int i = 0; i < grid.size(); i++) {
//			for (int j = 0; j < grid[i].size(); j++) {
//				if (mark[i][j] == 0 && grid[i][j] == '1') {
//					//BFS(mark, grid, i, j);
//					DFS(mark, grid, i, j);
//					island_num++;
//				}
//			}
//		}
//		return island_num;
//	}
//private:
//	//广度优先搜索
//	//void BFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
//	//	static const int dx[] = { -1,1,0,0 };
//	//	static const int dy[] = { 0,0,-1,1 };
//	//	queue<pair<int, int>> Q;	//广度优先搜索队列
//	//	Q.push(make_pair(x, y));	//将(x,y)push进入队列，并做标记
//	//	mark[x][y] = 1;
//	//	while (!Q.empty()) {
//	//		x = Q.front().first;
//	//		y = Q.front().second;
//	//		Q.pop();
//	//		for (int i = 0; i < 4; i++) {
//	//			int newx = dx[i] + x;
//	//			int newy = dy[i] + y;
//	//			if (newx < 0 || newx >= mark.size() || newy < 0 || newy >= mark[newx].size()) {
//	//				continue;
//	//			}
//	//			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
//	//				Q.push(make_pair(newx, newy));
//	//				mark[newx][newy] = 1;
//	//			}
//	//		}
//	//	}
//	//}
//
//	//深度优先搜索
//	void DFS(vector<vector<int>>& mark, vector<vector<char>>& grid, int x, int y) {
//		mark[x][y] = 1;
//		static const int dx[] = { -1,1,0,0 };
//		static const int dy[] = { 0,0,-1,1 };
//		for (int i = 0; i < 4; i++) {
//			int newx = x + dx[i];
//			int newy = y + dy[i];
//			if (newx < 0 || newx >= grid.size() || newy < 0 || newy >= mark[newx].size()) {
//				continue;
//			}
//			if (mark[newx][newy] == 0 && grid[newx][newy] == '1') {
//				DFS(mark, grid, newx, newy);
//			}
//		}
//	}
//};

//解法二
class Solution {
private:
	int d[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int m=0, n=0;
	vector<vector<bool>> visited;
	bool inArea(int x, int y) {
		return x >= 0 && x < m && y >= 0 && y < n;
	}
	void dfs(vector<vector<char>>& grid, int x, int y) {
		visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int newx = x + d[i][0];
			int newy = y + d[i][1];
			if (inArea(newx, newy) && !visited[newx][newy] && grid[newx][newy] == '1') {
				dfs(grid, newx, newy);
			}
		}
		return;
	}
public:
	int numIslands(vector<vector<char>>& grid) {
		m = grid.size();
		if (m == 0) {
			return 0;
		}
		n = grid[0].size();
		visited = vector<vector<bool>>(m, vector<bool>(n, false));
		int res = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == '1' && !visited[i][j]) {
					res++;
					dfs(grid, i, j);
				}
			}
		}
		return res;
	}
};

int main() {

	vector<vector<char>> grid;
	char str[10][10] = { "11100","11000","00100","00011" };
	for (int i = 0; i < 4; i++) {
		grid.push_back(vector<char>());
		for (int j = 0; j < 5; j++) {
			grid[i].push_back(str[i][j]);
		}
	}
	Solution solve;
	printf("%d\n", solve.numIslands(grid));

	return 0;
}