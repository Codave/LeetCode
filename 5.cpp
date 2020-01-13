#include<iostream>
#include<string>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		string res;
//		for (int i = 0; i < s.size(); i++) {
//			for (int j = i, k = i; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) {
//				if (res.size() < k - j + 1) {
//					res = s.substr(j, k - j + 1);
//				}
//			}
//			for (int j = i, k = i + 1; j >= 0 && k < s.size() && s[j] == s[k]; j--, k++) {
//				if (res.size() < k - j + 1) {
//					res = s.substr(j, k - j + 1);
//				}
//			}
//		}
//		return res;
//	}
//};

//解法二
class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		if (n < 2) return s;
		int dp[n][n];
		int ans = 1;
		int start = 0;
		memset(dp, 0, sizeof(dp));
		//边界
		for (int i = 0; i < n; i++) {
			dp[i][i] = 1;
			if (i < n - 1) {
				if (s[i] == s[i + 1]) {
					dp[i][i + 1] = 1;
					ans = 2;
					start = i;
				}
			}
		}
		//状态转移方程
		int L;
		for (L = 3; L <= n; L++) {
			for (int i = 0; i + L - 1 < n; i++) {
				int j = i + L - 1;
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
					dp[i][j] = 1;
					start = i;
					ans = L;
				}
			}
		}
		return s.substr(start, ans);
	}
};

int main() {

	string res = Solution().longestPalindrome("cbbd");

	return 0;
}