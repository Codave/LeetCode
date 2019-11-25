#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//�ⷨһ
class Solution {
public:
	vector<int> findAnagrams(string s, string t) {
		// �������¼��
		vector<int> res;
		int left = 0, right = 0;
		unordered_map<char, int> needs;
		unordered_map<char, int> window;
		for (char c : t) needs[c]++;
		int match = 0;

		while (right < s.size()) {
			char c1 = s[right];
			if (needs.count(c1)) {
				window[c1]++;
				if (window[c1] == needs[c1])
					match++;
			}
			right++;

			while (match == needs.size()) {
				// ��� window �Ĵ�С����
				// �Ͱ���ʼ���� left ������
				if (right - left == t.size()) {
					res.push_back(left);
				}
				char c2 = s[left];
				if (needs.count(c2)) {
					window[c2]--;
					if (window[c2] < needs[c2])
						match--;
				}
				left++;
			}
		}
		return res;
	}
};

int main() {

	string S = "cbaebabacd" ;
	string T = "abc";
	vector<int> res = Solution().findAnagrams(S, T);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}