#include<cstdio>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//	vector<vector<int>> combinationSum2(vector<int>& candidates,int target) {
//		vector<vector<int>> result;
//		vector<int> item;
//		set<vector<int>> res_set;  //去重使用集合set
//		sort(candidates.begin(), candidates.end());
//		/*result.push_back(item);*/
//		generate(0, candidates, result, item, res_set, 0, target);
//
//		//vector<vector<int>>target_result;	//存储最终结果
//		//for (int i = 0; i < result.size(); i++) {
//		//	int sum = 0;
//		//	for (int j = 0; j < result[i].size(); j++) {
//		//		sum += result[i][j];
//		//	}
//		//	if (sum == target) {
//		//		target_result.push_back(result[i]);
//		//	}
//		//}
//		return result;
//	}
//private:
//	void generate(int i, vector<int>& nums, vector<vector<int>>& result, vector<int>& item, set < vector<int>>& res_set, int sum, int target) {
//		if (i >= nums.size() || sum > target) {  //sum为当前子集item中的元素和
//			return;
//		}
//		sum += nums[i];
//		item.push_back(nums[i]);
//		if (target == sum && res_set.find(item) == res_set.end()) {
//			result.push_back(item);
//			res_set.insert(item);
//		}
//		generate(i + 1, nums, result, item, res_set, sum, target);
//		sum -= nums[i];
//		item.pop_back();
//		generate(i + 1, nums, result, item, res_set, sum, target);
//	}
//};

//解法二
class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<int> out;
		sort(candidates.begin(), candidates.end());
		sumDfs(candidates, target, 0, out);
		return res;
	}
	void sumDfs(vector<int>& candidates, int target, int start, vector<int>& out) {
		if (target < 0) {
			return;
		}
		if (target == 0) {
			res.push_back(out);
			return;
		}
		for (int i = start; i < candidates.size(); i++) {
			if (i > start && candidates[i] == candidates[i - 1]) continue;
			out.push_back(candidates[i]);
			sumDfs(candidates, target - candidates[i], i+1, out);
			out.pop_back();
		}
		return;
	}
private:
	vector<vector<int>> res;
};

int main() {
	vector<int> nums({ 10, 1, 2, 7, 6, 1, 5 });
	vector<vector<int>> result;
	Solution solve;
	result = solve.combinationSum2(nums,8);
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