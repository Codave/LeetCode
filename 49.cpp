#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<vector<string>> groupAnagrams(vector<string>& strs) {
//		map<string,vector<string>> anagram;
//		vector<vector<string>> result;
//		for (int i = 0; i < strs.size(); i++) {
//			string str = strs[i];
//			sort(str.begin(), str.end());
//			if (anagram.find(str) == anagram.end()) {
//				vector<string> item;
//				anagram[str] = item;
//			}
//			anagram[str].push_back(strs[i]);
//		}
//		map<string, vector<string>>::iterator it;
//		for (it = anagram.begin(); it != anagram.end(); it++) {
//			result.push_back((*it).second);
//		}
//		return result;
//	}
//};

//解法二
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		map<vector<int>, vector<string>> anagram;
		vector<vector<string>> result;
		for (int i = 0; i < strs.size(); i++) {
			vector<int> vec;
			change_to_vector(strs[i], vec);
			if (anagram.find(vec) == anagram.end()) {
				vector<string> item;
				anagram[vec] = item;
			}
			anagram[vec].push_back(strs[i]);
		}
		map<vector<int>, vector<string>>::iterator it;
		for (it = anagram.begin(); it != anagram.end(); it++) {
			result.push_back((*it).second);
		}
		return result;
	}
private:
	void change_to_vector(string& str, vector<int>& vec) {
		for (int i = 0; i < 26; i++) {
			vec.push_back(0);
		}
		for (int i = 0; i < str.length(); i++) {
			vec[str[i] - 'a']++;
		}
	}
};


int main() {

	vector<string> strs;
	strs.push_back("eat");
	strs.push_back("tea");
	strs.push_back("tan");
	strs.push_back("ate");
	strs.push_back("nat");
	strs.push_back("bat");
	Solution solve;
	vector<vector<string>> result = solve.groupAnagrams(strs);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			printf("[%s]", result[i][j].c_str());
		}
		printf("\n");
	}

	return 0;
}