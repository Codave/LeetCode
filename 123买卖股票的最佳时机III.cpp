class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		int cnt = 2;
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(cnt + 1, vector<int>(2, 0)));
		for (int i = 0; i < n; i++) {
			for (int k = 1; k <= cnt; k++) {
				if (i - 1 == -1) {
					dp[0][k][0] = 0;
					dp[0][k][1] = -prices[0];
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[n - 1][cnt][0];
	}
};