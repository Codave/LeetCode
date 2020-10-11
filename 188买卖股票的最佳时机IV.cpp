class Solution {
public:
	int maxProfit(int ck, vector<int>& prices) {
		int n = prices.size();
		if (ck > n / 2) return maxProfit_inf(prices);
		vector<vector<vector<int>>> dp(n, vector<vector<int>>(ck + 1, vector<int>(2, 0)));
		for (int i = 0; i < n; i++) {
			for (int k = 1; k <= ck; k++) {
				if (i - 1 == -1) {
					dp[0][k][0] = 0;
					dp[0][k][1] = -prices[0];
					continue;
				}
				dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
				dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
			}
		}
		return dp[n - 1][ck][0];
	}

	int maxProfit_inf(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		int dp_i_0 = 0;
		int dp_i_1 = INT_MIN;
		for (int i = 0; i < prices.size(); i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, temp - prices[i]);
		}
		return dp_i_0;
	}
};

