#include<vector>
#include<iostream>
using namespace std;

//解法一
//class Solution {
//public:
//	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//		vector<int> aux;
//		
//		for (int i = 0; i < m; i++) {
//			aux.push_back(nums1[i]);
//		}
//	
//		int i, j;
//		int k = 0;
//		for (i = 0, j = 0; i < aux.size()&&j < nums2.size();) {
//			if (aux[i] < nums2[j]) {
//				nums1[k++]=aux[i];
//				i++;
//			}
//			else {
//				nums1[k++] = nums2[j];
//				j++;
//			}
//		}
//		while (i < aux.size()) nums1[k++]=aux[i++];
//		while (j < nums2.size()) nums1[k++]=nums2[j++];
//		
//	}
//};

//解法二
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		int k = m + n - 1;
		m--;
		n--;
		while (m >= 0 && n >= 0) {
			if (nums1[m] < nums2[n]) {
				nums1[k--] = nums2[n--];
			}
			else {
				nums1[k--] = nums1[m--];
			}
		}
		while (n >= 0) {
			nums1[k--] = nums2[n--];
		}
	}
};

int main() {
	vector<int> a = { 1,4,5 };
	vector<int> b = { 2,3,8,9 };
	for (int i = 0; i < b.size(); i++) {
		a.push_back(0);
	}
	Solution().merge(a, 3, b, 4);
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	return 0;
}