#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp;
		for (int i = 0; i <= amount; i++) {	//初始化dp数组
			dp.push_back(-1);
		}
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {   //零钱可兑换要满足两个条件：1.零钱必须小于等于被兑换的数额；2.满足迭代，即兑换的零钱也必须能被兑换成零钱
					if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {	//使兑换的零钱张数尽量少
						dp[i] = dp[i - coins[j]] + 1;
					}
				}
			}
		}
		return dp[amount];
	}
};

int main() {

	Solution solve;
	vector<int> coins = {1, 2, 5, 7, 10};

	for (int i = 1; i <= 14; i++) {
		printf("dp[%d]=%d\n", i, solve.coinChange(coins, i));
	}

	return 0;
}