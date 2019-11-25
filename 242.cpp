#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() == 0 && t.size() == 0) return true;
		if (s.size() != t.size()) return false;

		unordered_map<int, int> tmap;
		unordered_map<int, int> window;
		for (char c : t) tmap[c]++;
		int right = 0;
		int match = 0;
		while (right < s.size()) {
			char c1 = s[right];
			if (tmap.count(c1)) {
				window[c1]++;
				if (window[c1] == tmap[c1]) {
					match++;
				}
			}
			right++;
			if(match == tmap.size()) {
				return true;	//���ȫ��ƥ��
			}
		}
		return false;
	}
};

int main() {
	string s = "anagram";
	string t = "nagaram";
	bool res = Solution().isAnagram(s, t);
	cout << res << endl;

	return 0;
}
