#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void solve(vector<vector<char> >& board) {
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O')
					solveDFS(board, i, j);
			}
		}
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				if (board[i][j] == 'O') board[i][j] = 'X';
				if (board[i][j] == '$') board[i][j] = 'O';
			}
		}
	}
	void solveDFS(vector<vector<char> >& board, int i, int j) {
		if (board[i][j] == 'O') {
			board[i][j] = '$';
			if (i > 0 && board[i - 1][j] == 'O')
				solveDFS(board, i - 1, j);
			if (j < board[i].size() - 1 && board[i][j + 1] == 'O')
				solveDFS(board, i, j + 1);
			if (i < board.size() - 1 && board[i + 1][j] == 'O')
				solveDFS(board, i + 1, j);
			if (j > 0 && board[i][j - 1] == 'O')
				solveDFS(board, i, j - 1);
		}
	}
};

int main() {
	vector<vector<char>> board = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'},
	};
	Solution().solve(board);
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[i].size(); j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}