#include<iostream>
#include<string>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<vector<string>> solveNQueens(int n) {
//		vector<vector<string>> result;
//		vector<vector<int>> mark;
//		vector<string> loction;
//		for (int i = 0; i < n; i++) {
//			mark.push_back((vector<int>()));
//			for (int j = 0; j < n; j++) {
//				mark[i].push_back(0);
//			}
//			loction.push_back("");
//			loction[i].append(n, '.');
//		}
//		generate(0, n, loction, result, mark);
//		return result;
//	}
//private:
//	void put_down_the_queen(int x, int y, vector<vector<int>> &mark) {
//		static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
//		static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
//		mark[x][y] = 1;
//		for (int i = 1; i < mark.size(); i++) {
//			for (int j = 0; j < 8; j++) {
//				int new_x = x + i * dx[j];
//				int new_y = y + i * dy[j];
//				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
//					mark[new_x][new_y] = 1;
//				}
//			}
//		}
//	}
//	void generate(int k, int n, vector<string>& location, vector<vector<string>>& result, vector<vector<int>>& mark) {
//		if (k==n) {
//			result.push_back(location);
//			return;
//		}
//		for (int i = 0; i < n; i++) {
//			if (mark[k][i]==0) {  //mark[i].find(0) != mark[i].end
//				vector<vector<int>> tmp_mark = mark;	//记录回溯前的mark镜像
//				location[k][i] = 'Q';	//记录当前皇后的位置
//				put_down_the_queen(k, i, mark);	//放置皇后
//				generate(k + 1, n, location, result, mark);	//递归下一行皇后放置
//				mark = tmp_mark;  //将mark重新赋值为回溯前状态
//				location[k][i] = '.';	//将当前尝试的皇后位置重新置 .
//			}
//		}
//	}
//};   

//解法二
class Solution {
private:
	vector<vector<string>> res;
	vector<bool> col, dia1, dia2;
	void putQueen(int n, int index, vector<int>& row) {
		
		if (index == n) {
			res.push_back(generateBoard(n, row));
			return;
		}
		for (int i = 0; i < n; i++) {
			if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
				row.push_back(i);
				col[i] = true;
				dia1[index + i] = true;
				dia2[index - i + n - 1] = true;
				putQueen(n, index + 1, row);
				col[i] = false;
				dia1[index + i] = false;
				dia2[index - i + n - 1] = false;
				row.pop_back();
			}
		}
		return;
	}
	vector<string> generateBoard(int n, vector<int>& row) {
		vector<string> board(n, string(n, '.'));
		for (int i = 0; i < n; i++) {
			board[i][row[i]] = 'Q';
		}
		return board;
	}
public:
	vector<vector<string>> solveNQueens(int n) {
		res.clear();
		col = vector<bool>(n, false);
		dia1 = vector<bool>(2 * n - 1, false);
		dia2 = vector<bool>(2 * n - 1, false);
		vector<int> row;
		putQueen(n, 0, row);
		return res;
	}
};

int main() {
	vector<vector<string>> result;
	Solution solve;
	result = solve.solveNQueens(4);
	for (int i = 0; i < result.size(); i++) {
		printf("i=%d\n", i);
		for (int j = 0; j < result[i].size(); j++) {
			printf("%s\n", result[i][j].c_str());
		}
		printf("\n");
	}

	return 0;
}