#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> count;
		for (char c:s) count[c]++;
		vector<pair<char, int>> v;
		for (auto it = count.begin(); it != count.end(); it++) {
			v.push_back(make_pair(it->first, it->second));
		}
		sort(v.begin(), v.end(), cmp);
		string res="";
		for (int i = 0; i < v.size(); i++) {
			while (v[i].second--) {
				res += v[i].first;
			}
		}
		return res;
	}
	static bool cmp(pair<char, int>& a, pair<char, int>& b) {
		return a.second > b.second;
	}
};

int main() {

	string s = "tree";
	string res = Solution().frequencySort(s);
	cout << res << endl;

	return 0;
}