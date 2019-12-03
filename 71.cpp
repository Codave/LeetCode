#include<iostream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;

class Solution {
public:
	string simplifyPath(string path) {
		stringstream is(path);
		vector<string> strs;
		string res;
		string tmp = "";
		while (getline(is, tmp, '/')) {
			if (tmp == "" || tmp == ".") {
				continue;
			}
			else if (tmp == ".." && !strs.empty()) {
				strs.pop_back();
			}
			else if (tmp != "..") {
				strs.push_back(tmp);
			}
		}
		for (string str : strs) {
			res += "/" + str;
		}
		if (res.empty()) {
			return "/";
		}
		return res;
	}
};

int main() {

	string path = "/../";
	string res = Solution().simplifyPath(path);
	cout << res << endl;

	return 0;
}