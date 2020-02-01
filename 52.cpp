#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<bool> col, dia1, dia2;
	int res = 0;
	void putQueen(int n, int index, vector<int>& row) {
		if (index == n) {
			res++;
		}
		for (int i = 0; i < n; i++) { //i:ÁÐºÅ index:ÐÐºÅ
			if (!col[i] && !dia1[index + i] && !dia2[index - i + n - 1]) {
				row.push_back(i);
				col[i] = true;
				dia1[index + i] = true;
				dia2[index - i + n - 1] = true;
				putQueen(n, index + 1, row);
				col[i] = false;
				dia1[index + i] = false;
				dia2[index - i + n - 1] = false;
			}
		}
	}
	int totalNQueens(int n) {
		col = vector<bool>(n, false);
		dia1 = vector<bool>(2 * n - 1, false);
		dia2 = vector<bool>(2 * n - 1, false);
		vector<int> row;
		putQueen(n, 0, row);
		return res;
	}
};

int main() {
	int res = Solution().totalNQueens(4);
	cout << res << endl;

	return 0;
}