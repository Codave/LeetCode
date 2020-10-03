#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstringTwoDistinct(string s) {
		int res = 0, left = 0;
		unordered_map<char, int> mp;
		for (int i = 0; i < s.size(); i++) {
			++mp[s[i]];
			while (mp.size() > 2) {
				if (--mp[s[left]] == 0) mp.erase(s[left]);
				++left;
			}
			res = max(res, i - left + 1);
		}
		return res;
	}
};