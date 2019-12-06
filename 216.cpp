#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum3(int k, int n) {
		vector<int> out;
		sum3Dfs(k, n, 1, out);
		return res;
	}
	void sum3Dfs(int k, int n, int level, vector<int>& out) {
		if (n < 0) {
			return;
		}
		if (n == 0 && out.size() == k) {
			res.push_back(out);
			return;
		}
		for (int i = level; i <= 9; i++) {
			if (n < i) return;
			out.push_back(i);
			sum3Dfs(k, n-i, i+1, out);
			out.pop_back();
		}
		return;
	}
private:
	vector<vector<int>> res;
};

int main() {
	vector<vector<int>> res = Solution().combinationSum3(3, 7);
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