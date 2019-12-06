#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//方法一
//
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int> >result;
//		vector<int> item;
//		result.push_back(item);
//		generate(0, nums, item, result);
//		return result;
//	}
//private:
//	void generate(int i, vector<int>& nums, vector<int>& item, vector<vector<int>>& result) {
//		if (i >= nums.size()) {
//			return;
//		}
//		item.push_back(nums[i]);
//		result.push_back(item);
//		generate(i + 1, nums, item, result);
//		item.pop_back();	//用二叉树的图来结合理解
//		generate(i + 1, nums, item, result);
//	}
//};

//解法二
//class Solution {
//public:
//	vector<vector<int> > subsets(vector<int>& S) {
//		vector<int> out;
//		sort(S.begin(), S.end());
//		getSubsets(S, 0, out);
//		return res;
//	}
//	void getSubsets(vector<int>& S, int pos, vector<int>& out) {
//		res.push_back(out);
//		for (int i = pos; i < S.size(); ++i) {
//			out.push_back(S[i]);
//			getSubsets(S, i + 1, out);
//			out.pop_back();
//		}
//	}
//private:
//	vector<vector<int> > res;
//};

//方法三
//class Solution {
//public:
//	vector<vector<int>> subsets(vector<int>& nums) {
//		vector<vector<int>> result;
//		int all_set = 1 << nums.size();
//		for (int i = 0; i < all_set; i++) {
//			vector<int> item;	//第一次循环i=0，item为空（初始化item为NULL），什么都没放进去
//			for (int j = 0; j < nums.size(); j++) {
//				if (i & 1<<j) {
//					item.push_back(nums[j]);
//				}
//			}
//			result.push_back(item);
//		}
//		return result;
//	}
//};

//方法四
//class Solution {
//public:
//	vector<vector<int> > subsets(vector<int>& S) {
//		vector<vector<int> > res(1);
//		sort(S.begin(), S.end());
//		for (int i = 0; i < S.size(); ++i) {
//			int size = res.size();
//			for (int j = 0; j < size; ++j) {
//				res.push_back(res[j]);
//				res.back().push_back(S[i]);
//			}
//		}
//		return res;
//	}
//};

int main() {
	
	vector<int> nums({ 4, 5, 6 });
	vector<vector<int>> result;
	Solution solve;
	result = solve.subsets(nums);
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