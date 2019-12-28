#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& A) {
		int len = A.size();
		if (len <= 1) { // ����ջ򳤶�Ϊ1
			return A;
		}

		int i = 0;
		while (i < len) {
			int j = i + 1;
			if (j < len && A[i] % 2 != 0) { // a[i]Ϊ������jǰ����ֱ���滻
				while (A[j] % 2 != 0) { // jΪ������ǰ��
					if (j == len - 1)// iΪ������jҲΪ������һֱ���Ƶ���ĩβ��֤�����涼������
						return A;
					j++;
				}
				// ��ʱjΪż��
				int count = j - i;
				int temp = A[i];
				A[i] = A[j];
				while (count > 1) {
					A[i + count] = A[i + count - 1];//�������
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
