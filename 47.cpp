#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

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
//		}
//		return;
//	}
//private:
//	vector<vector<int>> res;
//};

//解法二(Todo)
class Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		permute(nums, 0);
		return vector<vector<int>>(res.begin(), res.end());
	}
	void permute(vector<int>& nums, int start) {
		if (start >= nums.size()) res.insert(nums);
		for (int i = start; i < nums.size(); ++i) {
			if (i != start && nums[i] == nums[start]) continue;
			swap(nums[i], nums[start]);
			permute(nums, start + 1);
			swap(nums[i], nums[start]);
		}
	}
private:
	set<vector<int>> res;
};

int main() {

	vector<int> nums = { 1,1,3 };
	vector<vector<int>> res = Solution().permuteUnique(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j];
		}
		cout << endl;
	}

	return 0;
}