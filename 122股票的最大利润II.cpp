//解法一
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		int res = 0, n = prices.size();
//		for (int i = 0; i < n - 1; i++) {
//			if (prices[i] < prices[i + 1]) {
//				res += prices[i + 1] - prices[i];
//			}
//		}
//		return res;
//	}
//};


//解法二
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		for (int i = 0; i < prices.size(); i++) {
			if (i - 1 == -1) {
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				continue;
			}
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
		}
		return dp[n - 1][0];
	}
};