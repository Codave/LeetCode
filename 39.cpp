#include<iostream>
#include<vector>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//		vector<int> out;
//		sumDfs(candidates, target, 0, out);
//		return res;
//	}
//	void sumDfs(vector<int>& candidates, int target,int index, vector<int>& out) {
//		if (target < 0) {
//			return;
//		}
//		if (target == 0) {
//			res.push_back(out);
//			return;
//		}
//		for (int i = index; i < candidates.size(); i++) {
//			out.push_back(candidates[i]);
//			sumDfs(candidates, target - candidates[i], i, out);
//			out.pop_back();
//		}
//		return;
//	}
//private:
//	vector<vector<int>> res;
//};


//解法二（todo)
class Solution {
	vector<vector<int>> res;
	vector<int> t;
public:
	void helper(vector<int>& candidates, int target) {
		for (int i = 0; i < candidates.size(); i++) {
			if ((candidates[i] > target) || (t.size() && candidates[i] < t[t.size() - 1])) continue;
			t.push_back(candidates[i]);
			if (candidates[i] == target) res.push_back(t);
			else helper(candidates, target - candidates[i]);
			t.pop_back();
		}
	}
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		res.clear();
		t.clear();
		helper(candidates, target);
		return res;
	}
};

int main() {
	vector<int> nums = { 2,3,6,7 };
	vector<vector<int>> res = Solution().combinationSum(nums, 7);
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