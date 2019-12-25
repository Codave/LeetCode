#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
	//memo[i][c]��ʾʹ������Ϊ[0...i]����ЩԪ�أ��Ƿ������ȫ���һ������Ϊc�ı���
	//-1 ��ʾΪδ���㣻 0 ��ʾ��������䣻 1 ��ʾ�������
	vector<vector<int>> memo;

	//ʹ��nums[0...index]���Ƿ������ȫ���һ������Ϊsum�ı���
	bool tryPartition(const vector<int>& nums, int index, int sum) {
		if (sum == 0) {
			return true;
		}
		if (sum < 0 || index < 0) {
			return false;
		}
		if (memo[index][sum] != -1) {
			return memo[index][sum]==1;  //return memo[index][sum];
		}
		memo[index][sum] = (tryPartition(nums, index - 1, sum) || tryPartition(nums, index - 1, sum - nums[index])) ? 1 : 0;
		return memo[index][sum] == 1;
	}
public:
	bool canPartition(vector<int>& nums) {
		int sum = 0;
		for (int i = 0; i < nums.size(); i++) {
			sum += nums[i];
		}
		if (sum % 2 != 0) {
			return false;
		}
		memo = vector<vector<int>>(nums.size(), vector<int>(sum / 2 + 1,-1));
		return tryPartition(nums, nums.size() - 1, sum / 2);
	}
};

int main() {
	vector<int> nums = { 1, 5, 11, 5 };
	cout << Solution().canPartition(nums) << endl;

	return 0;
}