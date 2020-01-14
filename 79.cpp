#include<iostream>
#include<vector>
using namespace std;

//解法一
//class Solution {
//private:
//	int d[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
//	int m, n;
//	vector<vector<bool>> visited;
//	bool inArea(int x, int y) {
//		return x >= 0 && x < m && y >= 0 && y < n;
//	}
//	bool searchWord(const vector<vector<char>>& board, const string& word, int index, int startx, int starty) {
//
//
//		if (index == word.size() - 1) {
//			return board[startx][starty] == word[index];
//		}
//		if (board[startx][starty] == word[index]) {
//			visited[startx][starty] = true;
//			for (int i = 0; i < 4; i++) {
//				int newx = startx + d[i][0];
//				int newy = starty + d[i][1];
//				if (inArea(newx, newy) && !visited[newx][newy] && searchWord(board, word, index + 1, newx, newy)) {
//					return true;
//				}
//			}
//			visited[startx][starty] = false;
//		}
//		return false;
//	}
//public:
//	bool exist(vector<vector<char>>& board, string word) {
//		m = board.size();
//		n = board[0].size();
//		visited = vector<vector<bool>>(m, vector<bool>(n, false));
//		for (int i = 0; i < board.size(); i++) {
//			for (int j = 0; j < board[i].size(); j++) {
//				if (searchWord(board, word, 0, i, j)) {
//					return true;
//				}
//			}
//		}
//		return 0;
//	}
//};

//解法二
class Solution {
public:
	int n, m;
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	bool exist(vector<vector<char>>& board, string word) {
		if (board.empty() || board[0].empty()) return false;
		n = board.size(), m = board[0].size();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (dfs(board, i, j, word, 0)) {
					return true;
				}
			}
		}
		return false;
	}
	bool dfs(vector<vector<char>>& board, int x, int y, string& word, int u) {
		if (board[x][y] != word[u]) return false;
		if (u == word.size() - 1) return true;
		board[x][y] = '.';
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && a < n && b >= 0 && b < m) {
				if (dfs(board, a, b, word, u + 1)) {
					return true;
				}
			}
		}
		board[x][y] = word[u];
		return false;
	}
};

int main() {
	vector<vector<char>> board = {
		{'A', 'A'}
		/*{'S', 'F', 'C', 'S'},
		{'A', 'D', 'E', 'E'}*/
	};
	bool res = Solution().exist(board, "AA");
	cout << res << endl;
	return 0;
}