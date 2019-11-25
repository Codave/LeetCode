#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		unordered_map<int, int> smap;
		unordered_map<int, int> tmap;
		for (int i = 0; i <s.size(); i++) {
			char ss = s[i];
			char tt = t[i];
			if (smap.count(ss)) {
				if (smap[ss] != tt) return false;
			}
			else if (tmap.count(tt)) {
				if (tmap[tt] != ss) return false;
			}
			else {
				smap[ss] = tt;
				tmap[tt] = ss;
			}
		}
		return true;
	}
};

int main() {

	string s = "aa";
	string t = "ab";
	cout << Solution().isIsomorphic(s, t) << endl;

	return 0;
}