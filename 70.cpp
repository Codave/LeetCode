#include<vector>
#include<cstdio>
using namespace std;

//class Solution {
//public:
//	int climbStairs(int n) {
//		vector<int> dp(n + 1, 0);
//		dp[1] = 1;
//		dp[2] = 2;
//		for (int i = 3; i <= n; i++) {
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//		return dp[n];
//	}
//};

//class Solution {
//public:
//	int climbStairs(int n) {
//		vector<int> dp(n + 1, 0);
//		dp[1] = 1;
//		dp[0] = 1;
//		for (int i = 2; i <= n; i++) {
//			dp[i] = dp[i - 1] + dp[i - 2];
//		}
//		return dp[n];
//	}
//};

class Solution {
private:
	vector<int> dp;
	int calcWays(int n) {
		if (n == 1)	return 1;
		if (n == 2) return 2;
		if (dp[n] == -1) {
			dp[n] = calcWays(n - 1) + calcWays(n - 2);
		}
		return dp[n];
	}
public:
	int climbStairs(int n) {
		dp = vector<int>(n + 1, -1);
		return calcWays(n);
	}
};

int main() {

	Solution solve;
	printf("%d\n", solve.climbStairs(3));

	return 0;
}