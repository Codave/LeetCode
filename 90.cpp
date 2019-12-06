#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//		vector<vector<int>> result;
//		vector<int> item;
//		set<vector<int>> res_set;  //去重使用集合set
//		sort(nums.begin(), nums.end());
//		result.push_back(item);
//		generate(0, nums, result, item, res_set);
//		return result;
//	}
//private:
//	void generate(int i, vector<int>& nums, vector<vector<int>>& result, vector<int>& item, set < vector<int>>& res_set) {
//		if (i >= nums.size()) {
//			return;
//		}
//		item.push_back(nums[i]);
//		if (res_set.find(item) == res_set.end()) {
//			result.push_back(item);
//			res_set.insert(item);
//		}
//		generate(i + 1, nums, result, item, res_set);
//		item.pop_back();
//		generate(i + 1, nums, result, item, res_set);
//	}
//};


//解法二
class Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& S) {
		if (S.empty()) return {};
		vector<vector<int>> res;
		vector<int> out;
		sort(S.begin(), S.end());
		getSubsets(S, 0, out, res);
		return res;
	}
	void getSubsets(vector<int>& S, int pos, vector<int>& out, vector<vector<int>>& res) {
		res.push_back(out);
		for (int i = pos; i < S.size(); ++i) {
			//if (i > pos&& S[i - 1] == S[i]) continue;
			out.push_back(S[i]);
			getSubsets(S, i + 1, out, res);
			out.pop_back();
			while (i + 1 < S.size() && S[i] == S[i + 1]) ++i;
		}
	}
};

int main() {
	vector<int> nums({ 1, 2, 2 });
	vector<vector<int>> result;
	Solution solve;
	result = solve.subsetsWithDup(nums);
	for (int i = 0; i < result.size(); i++) {
		if (result[i].size() == 0) {
			printf("[]");
		}
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%d]", result[i][j]);
		}
		printf("\n");
	}

	return 0;
}