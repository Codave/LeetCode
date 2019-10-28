#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<string>> solveNQueens(int n) {
		vector<vector<string>> result;
		vector<vector<int>> mark;
		vector<string> loction;
		for (int i = 0; i < n; i++) {
			mark.push_back((vector<int>()));
			for (int j = 0; j < n; j++) {
				mark[i].push_back(0);
			}
			loction.push_back("");
			loction[i].append(n, '.');
		}
		generate(0, n, loction, result, mark);
		return result;
	}
private:
	void put_down_the_queen(int x, int y, vector<vector<int>> &mark) {
		static const int dx[] = { -1,1,0,0,-1,-1,1,1 };
		static const int dy[] = { 0,0,-1,1,-1,1,-1,1 };
		mark[x][y] = 1;
		for (int i = 1; i < mark.size(); i++) {
			for (int j = 0; j < 8; j++) {
				int new_x = x + i * dx[j];
				int new_y = y + i * dy[j];
				if (new_x >= 0 && new_x < mark.size() && new_y >= 0 && new_y < mark.size()) {
					mark[new_x][new_y] = 1;
				}
			}
		}
	}
	void generate(int k, int n, vector<string>& location, vector<vector<string>>& result, vector<vector<int>>& mark) {
		if (k==n) {
			result.push_back(location);
			return;
		}
		for (int i = 0; i < n; i++) {
			if (mark[k][i]==0) {  //mark[i].find(0) != mark[i].end
				vector<vector<int>> tmp_mark = mark;	//记录回溯前的mark镜像
				location[k][i] = 'Q';	//记录当前皇后的位置
				put_down_the_queen(k, i, mark);	//放置皇后
				generate(k + 1, n, location, result, mark);	//递归下一行皇后放置
				mark = tmp_mark;  //将mark重新赋值为回溯前状态
				location[k][i] = '.';	//将当前尝试的皇后位置重新置 .
			}
		}
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