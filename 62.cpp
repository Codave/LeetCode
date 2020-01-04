#include<iostream>
#include<vector>
using namespace std;

//方法一(动态规划)
//class Solution {
//public:
//	int uniquePaths(int m, int n) {
//		int dp[m][n] = { 0 };
//		for (int i = 0; i < n; i++) {
//			dp[0][i] = 1;
//		}
//		for (int i = 0; i < m; i++) {
//			dp[i][0] = 1;
//		}
//		for (int i = 1; i < m; i++) {
//			for (int j = 1; j < n; j++) {
//				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
//			}
//		}
//		return dp[m - 1][n - 1];
//	}
//};

//方法二(dfs+记忆化搜索)
class Solution {
public:
	vector<vector<int>> memo;
	int uniquePaths(int m, int n) {
		memo = vector<vector<int>>(m, vector<int>(n, -1));
		return dfs(m, n, 0, 0);
	}
	int dfs(int m, int n, int x, int y) {
		if (memo[x][y] != -1) {
			return memo[x][y];
		}
		if (x == m - 1 && y == n - 1) {
			return 1;
		}
		if (x == m - 1 && y < n - 1) {
			return 1;
		}
		if (y == n - 1 && x < m - 1) {
			return 1;
		}
		if (x + 1 < m && y + 1 < n) {
			memo[x][y] = dfs(m, n, x + 1, y) + dfs(m, n, x, y + 1);
		}
		return memo[x][y];
	}
};

int main() {
	Solution().uniquePaths(3, 2);

	return 0;
}