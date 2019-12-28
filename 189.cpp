// �ⷨһ
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> t = nums;
		for (int i = 0; i < nums.size(); ++i) {
			nums[(i + k) % nums.size()] = t[i];
		}
	}
};

//�ⷨ��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0) return;
		int n = nums.size();
		reverse(nums.begin(), nums.begin() + n - k);
		reverse(nums.begin() + n - k, nums.end());
		reverse(nums.begin(), nums.end());
	}
};

//�ⷨ��
class Solution {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k %= nums.size()) == 0) return;
		int n = nums.size();
		for (int i = 0; i < n - k; ++i) {
			nums.push_back(nums[0]);
			nums.erase(nums.begin());
		}
	}
};