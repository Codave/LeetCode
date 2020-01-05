#include<iostream>
using namespace std;

//�ⷨһ
// class Solution{
// public:
// 	int mySqrt(int x) {
// 		int l = 0;
// 		int r = x;
// 		while (l < r) {
// 			int mid = l + (long)r + 1 >> 1;
// 			if (mid <= x / mid) l = mid ;
// 			else r = mid-1;
// 		}
// 		return r;
// 	}
// };

//�ⷨ������ʵ�ͽⷨһ��һ���ģ�
class Solution {
public:
	int mySqrt(int x) {
		int l = 0;
		int r = x;
		while (l < r) {
			int mid = l + (long)r + 1 >> 1;
			if (mid > x / mid) r = mid - 1;
			else l = mid;
		}
		return r;
	}
};

int main() {
	int res = Solution().mySqrt(12);
	cout << res << endl;

	return 0;
}