#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

//解法一
class Solution {
public:
	vector<int> findAnagrams(string s, string t) {
		// 用数组记录答案
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
				// 如果 window 的大小合适
				// 就把起始索引 left 加入结果
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

////解法二
//class Solution {
//public:
//	string minWindow(string s, string t) {
//		int count[256] = { 0 };
//		for (auto c : t) ++count[c];
//		int len = 0, minLength = s.length();
//		string res;
//		for (int l = 0, r = 0; r < s.length(); ++r) {
//			count[s[r]]--;
//			if (count[s[r]] >= 0) ++len;
//			while (len == t.length()) {
//				if (r - l + 1 <= minLength) {
//					minLength = r - l + 1;
//					res = s.substr(l, r - l + 1);
//				}
//				count[s[l]]++;
//				if (count[s[l]] > 0) --len;
//				++l;
//			}
//		}
//		return res;
//	}
//};

int main() {

	string S = "cbaebabacd" ;
	string T = "abc";
	vector<int> res = Solution().findAnagrams(S, T);
	for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++) {
		cout << *iter << " ";
	}

	return 0;
}