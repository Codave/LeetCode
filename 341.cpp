#include<iostream>
#include<vector>
#include<string>
using namespace std;

//解法一
class Solution {
public:
	vector<string> readBinaryWatch(int num) {
		vector<string> res;
		//直接遍历  0:00 -> 12:00   每个时间有多少1
		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 60; j++) {
				if (count(i) + count(j) == num) {
					res.push_back(to_string(i) + ":" +(j < 10 ? "0" + to_string(j) : to_string(j)));
				}
			}
		}
		return res;
	}
	//计算二进制中1的个数
	int count(int n) {
		int res = 0;
		while (n != 0) {
			n = n & (n - 1);
			res++;
		}
		return res;
	}
};

//解法二
//class Solution {
//private:
//	vector<string>res;
//public:
//	vector<string> readBinaryWatch(int num) {
//		int cur = 0;
//		backtrack(0, cur, num);
//		return res;
//	}
//	void backtrack(int k, int cur, int num) {
//		int min = cur % 64;
//		int hour = cur >> 6;
//		if (hour >= 12 || min >= 60) return;
//		if (num == 0) {
//			string m = to_string(min);
//			if (m.size() == 1) m = "0" + m;
//			res.push_back(to_string(hour) + ":" + m);
//			return;
//		}
//		for (int i = k; i < 10; i++) {
//			int bit = (1 << i);
//			cur += bit;
//			backtrack(i + 1, cur, num - 1);
//			cur -= bit;
//		}
//	}
//};

int main() {

	vector<string> res = Solution().readBinaryWatch(2);
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << " ";
	}

	return 0;
}