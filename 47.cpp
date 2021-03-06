#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//解法一（debug)
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		
//		vector<int> out, visited(nums.size(), 0);
//		sort(nums.begin(), nums.end());
//		permuteUniqueDFS(nums, 0, visited, out);
//		return res;
//	}
//	void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out) {
//		if (level >= nums.size()) { 
//			cout << "新排列：";
//			for (int i = 0; i < out.size(); i++) {
//				cout << out[i];
//			}
//			cout << endl;
//			res.push_back(out); 
//			return;
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			if (visited[i] == 1) {
//				printf("nums[%d]:%d之前访问过了\n",i, nums[i]);
//				continue;
//			}
//			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) { 
//				printf("前一个相同的元素访问结束，不必再重复做相同工作，跳过num[%d]:%d\n", i, nums[i]);
//				continue;
//			}
//			visited[i] = 1;
//			printf("注意区分相同数字-->把num[%d]:%d放进去\n", i,nums[i]);
//			out.push_back(nums[i]);
//			permuteUniqueDFS(nums, level + 1, visited, out);
//			printf("把num[%d]:%d抛出去\n", i,nums[i]);
//			out.pop_back();
//			printf("让num[%d]:%d恢复访问,visit置为0\n", i, nums[i]);
//			visited[i] = 0;
//			
//			while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
//				printf("----------------------------------------------------------\n");
//				++i;
//			}
//		}
//		return;
//	}
//private:
//	vector<vector<int>> res;
//};

//解法一
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//
//		vector<int> out, visited(nums.size(), 0);
//		sort(nums.begin(), nums.end());
//		permuteUniqueDFS(nums, 0, visited, out);
//		return res;
//	}
//	void permuteUniqueDFS(vector<int>& nums, int level, vector<int>& visited, vector<int>& out) {
//		if (level >= nums.size()) {
//			res.push_back(out);
//			return;
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			if (visited[i] == 1) continue;
//			// if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) continue;
//			visited[i] = 1;
//			out.push_back(nums[i]);
//			permuteUniqueDFS(nums, level + 1, visited, out);
//			out.pop_back();
//			visited[i] = 0;
//			while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
//				++i;
//			}
//		}
//		return;
//	}
//private:
//	vector<vector<int>> res;
//};

////解法二(Todo)
//class Solution {
//public:
//	vector<vector<int>> permuteUnique(vector<int>& nums) {
//		permute(nums, 0);
//		return vector<vector<int>>(res.begin(), res.end());
//	}
//	void permute(vector<int>& nums, int start) {
//		if (start >= nums.size()) res.insert(nums);
//		for (int i = start; i < nums.size(); ++i) {
//			if (i != start && nums[i] == nums[start]) continue;
//			swap(nums[i], nums[start]);
//			permute(nums, start + 1);
//			swap(nums[i], nums[start]);
//		}
//	}
//private:
//	set<vector<int>> res;
//};

//解法三
class Solution {
public:
	int n;
	vector<vector<int>> ans;
	vector<int> path;
	vector<bool> st;

	vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		st = vector<bool>(n);
		path = vector<int>(n);
		sort(nums.begin(), nums.end());
		dfs(nums, 0, 0);
		return ans;
	}
	void dfs(vector<int>& nums, int u, int start) {
		if (u == n) {
			ans.push_back(path);
			return;
		}
		for (int i = start; i < n; i++) {
			if (!st[i]) {
				st[i] = true;
				path[i] = nums[u];
				dfs(nums, u + 1, u + 1 < n && nums[u + 1] == nums[u] ? i + 1 : 0);
				st[i] = false;
			}
		}
	}
};


int main() {

	vector<int> nums = { 1,1,1,3 };
	vector<vector<int>> res = Solution().permuteUnique(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}