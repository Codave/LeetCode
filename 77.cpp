#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	vector<vector<int>> res;
	void generateCombinations(int n, int k, int start, vector<int>& c) {
		if (c.size() == k) {
			res.push_back(c);
			return;
		}
		for (int i = start; i <= n - (k-c.size()) + 1; i++) {
			c.push_back(i);
			generateCombinations(n, k, i + 1, c);
			c.pop_back();
		}
		return;
	}
public:
	vector<vector<int>> combine(int n, int k) {
		
		res.clear();
		if (n <= 0 || k <= 0|| n < k) {
			return res;
		}
		vector<int> c;
		generateCombinations(n, k, 1, c);
		return res;
	}
};

int main() {

	vector<vector<int>> res = Solution().combine(4, 2);
	for (vector<vector<int>>::iterator iter = res.begin(); iter != res.end(); iter++) {
		for (vector<int>::iterator it = (*iter).begin(); it != (*iter).end(); it++) {
			cout << *it;
		}
		cout << endl;
	}

	return 0;
}