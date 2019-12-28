#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int len = A.size();
		if (len <= 1) { // 数组空或长度为1
			return A;
		}

		int i = 0;
		while (i < len) {
			int j = i + 1;
			if (j < len && A[i] % 2 != 0) { // a[i]为奇数，j前进，直到替换
				while (A[j] % 2 != 0) { // j为奇数，前进
					if (j == len - 1)// i为奇数，j也为奇数，一直后移到了末尾，证明后面都是奇数
						return A;
					j++;
				}
				// 此时j为偶数
				int count = j - i;
				int temp = A[i];
				A[i] = A[j];
				while (count > 1) {
					A[i + count] = A[i + count - 1];//数组后移
					count--;
				}
				A[i + 1] = temp;
			}
			i++;
		}
		return A;
	}
};

int main() {
	//vector<int> num = { 3,1,2,4 };
	vector<int> num = { 2,4,3};
	vector<int> res = Solution().sortArrayByParity(num);
	for (auto it = res.begin(); it != res.end(); it++) {
		cout << *it << " ";
	}

	return 0;
}
