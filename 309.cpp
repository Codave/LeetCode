class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		int dp_i_0 = 0, dp_i_1 = INT_MIN;
		int dp_pre_0 = 0;
		for (int i = 0; i < n; i++) {
			int temp = dp_i_0;
			dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
			dp_i_1 = max(dp_i_1, dp_pre_0 - prices[i]);
			dp_pre_0 = temp;
		}
		return dp_i_0;
	}
};