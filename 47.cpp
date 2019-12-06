#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
using namespace std;

//�ⷨһ
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
//			cout << "�����У�";
//			for (int i = 0; i < out.size(); i++) {
//				cout << out[i];
//			}
//			cout << endl;
//			res.push_back(out); 
//			return;
//		}
//		for (int i = 0; i < nums.size(); ++i) {
//			if (visited[i] == 1) {
//				printf("nums[%d]:%d֮ǰ���ʹ���\n",i, nums[i]);
//				continue;
//			}
//			if (i > 0 && nums[i] == nums[i - 1] && visited[i - 1] == 0) { 
//				printf("ǰһ����ͬ��Ԫ�ط��ʽ������������ظ�����ͬ����������num[%d]:%d\n", i, nums[i]);
//				continue;
//			}
//			visited[i] = 1;
//			printf("ע��������ͬ����-->��num[%d]:%d�Ž�ȥ\n", i,nums[i]);
//			out.push_back(nums[i]);
//			permuteUniqueDFS(nums, level + 1, visited, out);
//			printf("��num[%d]:%d�׳�ȥ\n", i,nums[i]);
//			out.pop_back();
//			printf("��num[%d]:%d�ָ�����,visit��Ϊ0\n", i, nums[i]);
//			visited[i] = 0;
//		}
//		return;
//	}
//private:
//	vector<vector<int>> res;
//};

//�ⷨ��(Todo)
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