class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0) {
			return 0;
		}
		int minPrice = prices[0];
		int res = 0;
		for (int i = 0; i < prices.size(); i++) {
			minPrice = min(minPrice, prices[i]);
			res = max(res, prices[i] - minPrice);
		}
		return res;
	}
};