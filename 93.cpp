#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		string ip;
		helper(s, 0, ip);
		return res;
	}
	void helper(string s, int n, string ip) {
		if (n == 4) {
			if (s.empty()) res.push_back(ip);
		}
		else {
			for (int k = 1; k < 4; ++k) {
				if (s.size() < k) break;
				int val = atoi(s.substr(0, k).c_str());
				if (val > 255 || k != std::to_string(val).size()) continue;
				helper(s.substr(k), n + 1, ip + s.substr(0, k) + (n == 3 ? "" : "."));
			}
		}
		return;
	}
private:
	vector<string> res;
};

int main() {
	string str = "25525511135";
	vector<string> res = Solution().restoreIpAddresses(str);
	for (vector<string>::iterator iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}