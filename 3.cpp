#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//解法一
//class Solution {
//public:
//	int lengthOfLongestSubstring(string s) {
//		int begin=0;
//		int result=0;
//		string word = "";
//		int char_map[128] = { 0 };
//		for (int i = 0; i < s.length(); i++) {
//			char_map[s[i]]++;
//			if (char_map[s[i]] == 1) {
//				word += s[i];
//				if (result < word.length()) {  //打擂法更新最大值
//					result = word.length();
//				}
//			}
//			else {
//				while (char_map[s[i]]>1) {
//					char_map[s[begin]]--;
//					begin++;
//				}
//				word = "";
//				for (int j = begin; j <= i; j++) {
//					word += s[j];
//				}
//			}
//		}
//		return result;
//	}
//};

//解法二
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int freq[256] = { 0 };
		int l = 0, r = -1;
		int res = 0;

		while (l < s.size()) {
			if (r + 1 < s.size() && freq[s[r + 1]] == 0) {
				freq[s[++r]]++;
			}
			else {
				freq[s[l++]]--;
			}
			res = max(res, r - l + 1);
		}

		return res;
	}
};

int main() {

	string s = "abcbadab";
	Solution solve;
	printf("%d\n", solve.lengthOfLongestSubstring(s));

	return 0;
}