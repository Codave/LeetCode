#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//解法一
//class Solution {
//public:
//	int maxProfit(vector<int>& prices) {
//		if (prices.size() == 0) {
//			return 0;
//		}
//		int minPrice = prices[0];
//		int res = 0;
//		for (int i = 0; i < prices.size(); i++) {
//			minPrice = min(minPrice, prices[i]);
//			res = max(res, prices[i] - minPrice);
//		}
//		return res;
//	}
//};

//解法二
class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) {
			return 0;
		}
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(2, 0));
		for (int i = 0; i < n; i++) {
			if (i - 1 == -1) {
				dp[i][0] = 0;
				dp[i][1] = -prices[i];
				continue;
			}
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
			dp[i][1] = max(dp[i - 1][1], -prices[i]);
		}
		return dp[n - 1][0];
	}
};