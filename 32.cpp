#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

//解法一
class Solution {
public:
	int longestValidParentheses(string s) {
		int res = 0, start = 0, n = s.size();
		stack<int> st;
		for (int i = 0; i < n; i++) {
			if (s[i] == '(') st.push(i);
			else if (s[i] == ')') {
				if (st.empty()) start = i + 1;
				else {
					st.pop();
					res = st.empty() ? max(res, i - start + 1) : max(res, i - st.top());
				}
			}
		}
		return res;
	}
};

//解法二
class Solution {
public:
	int longestValidParentheses(string s) {
		int res = 0, left = 0, right = 0, n = s.size();
		for (int i = 0; i < n; ++i) {
			s[i] == '(' ? ++left : ++right;
			if (left == right) res = max(res, 2 * right);
			else if (right > left) left = right = 0;
		}
		left = right = 0;
		for (int i = n-1; i > 0; i--) {
			s[i] == '(' ? ++left : ++right;
			if (left == right) res = max(res, 2 * left);
			else if (left > right) left = right = 0;
		}
		return res;
	}
};

int main() {
	string str = "())((())";
	int res = Solution().longestValidParentheses(str);
	cout << res << endl;

	return 0;
}