#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string>> res;
		vector<string> out;
		helper(s, 0, out, res);
		return res;
	}
	void helper(string s, int start, vector<string>& out, vector<vector<string>>& res) {
		if (start == s.size()) { res.push_back(out); return; }
		for (int i = start; i < s.size(); ++i) {
			if (!isPalindrome(s, start, i)) continue;
			out.push_back(s.substr(start, i - start + 1));
			helper(s, i + 1, out, res);
			out.pop_back();
		}
	}
	bool isPalindrome(string s, int start, int end) {
		while (start < end) {
			if (s[start] != s[end]) return false;
			++start; --end;
		}
		return true;
	}
};

int main() {

	string str = "aab";
	vector<vector<string>> res = Solution().partition(str);
	/*for (auto it = res.begin(); it != res.end(); it++) {
		for (auto jt = (*it).begin(); jt != (*it).end(); jt++) {
			cout << *jt<<" ";
		}
		cout << endl;
	}*/

	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size();j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}