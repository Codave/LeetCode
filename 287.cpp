//�ⷨһ������  ������ [1, n] ����������������е� mid��Ȼ������������飬ͳ������С�ڵ��� mid �����ĸ������������С�ڵ��� mid����˵���ظ�ֵ�� [mid+1, n] ֮�䣬��֮���ظ�ֵӦ�� [1, mid-1] ֮�䣬Ȼ���������ƣ�ֱ���������
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int left = 1, right = nums.size();
		while (left < right) {
			int mid = left + (right - left) / 2, cnt = 0;
			for (int num : nums) {
				if (num <= mid) ++cnt;
			}
			if (cnt <= mid) left = mid + 1;
			else right = mid;
		}
		return right;
	}
};

//�ⷨ�� ѭ�����   ����ָ��
class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int slow = 0, fast = 0, t = 0;
		while (true) {
			slow = nums[slow];
			fast = nums[nums[fast]];
			if (slow == fast) break;
		}
		while (true) {
			slow = nums[slow];
			t = nums[t];
			if (slow == t) break;
		}
		return slow;
	}
};