#include<cstdio>
#include<vector>
using namespace std;

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> dp;
		for (int i = 0; i <= amount; i++) {	//��ʼ��dp����
			dp.push_back(-1);
		}
		dp[0] = 0;
		for (int i = 1; i <= amount; i++) {
			for (int j = 0; j < coins.size(); j++) {
				if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {   //��Ǯ�ɶһ�Ҫ��������������1.��Ǯ����С�ڵ��ڱ��һ������2.������������һ�����ǮҲ�����ܱ��һ�����Ǯ
					if (dp[i] == -1 || dp[i] > dp[i - coins[j]] + 1) {	//ʹ�һ�����Ǯ����������
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