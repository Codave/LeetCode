#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<unordered_map>
using namespace std;

//解法一
//class Solution {
//public:
//	vector<string> findRepeatedDnaSequences(string s) {
//		map<string, int> word_map;
//		vector<string> result;
//		for (int i = 0; i < s.length(); i++) {
//			string word = s.substr(i, 10);
//			if (word_map.find(word) != word_map.end()) {
//				word_map[word] += 1;
//			}
//			else {
//				word_map[word] = 1;
//			}
//		}
//		map<string, int>::iterator it;
//		for (it = word_map.begin(); it != word_map.end(); it++) {
//			if (it->second > 1) {
//				result.push_back(it->first);
//			}
//		}
//		return result;
//	}
//};

//解法二
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		unordered_map<string, int> hash;
		vector<string> res;
		for (int i = 0; i + 10 <= s.size(); i++) {
			string str = s.substr(i, 10);
			hash[str]++;
			if (hash[str] == 2) res.push_back(str);
		}
		return res;
	}
};

//解法三 没搞懂
int g_hash_map[1048576] = { 0 };
string change_int_to_DNA(int DNA) {
	static const char DNA_CHAR[] = { 'A','C','G','T' };
	string str;
	for (int i = 0; i < 10; i++) {

	}
}
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> result;
		if (s.length() < 10) {
			return result;
		}
		for (int i = 0; i < 1048576; i++) {
			g_hash_map[i] = 0;
		}
		int char_map[128] = { 0 };
		char_map['A'] = 0;
		char_map['C'] = 1;
		char_map['G'] = 2;
		char_map['T'] = 3;
		int key = 0;
		for (int i = 9; i >= 0; i--) {
			key = (key << 2) + char_map[s[i]];
		}
		g_hash_map[key] = 1;
		for (int i = 10; i < s.length(); i++) {
			key = key >> 2;
			key = key | (char_map[s[i]] << 18);
			g_hash_map[key]++;
		}
		for (int i = 0; i < 1048576; i++) {
			if (g_hash_map[i] > 1) {
				result.push_back(change_int_to_DNA(i));
			}
		}
		return result;
	}
};

int main() {
	string str = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
	Solution solve;
	vector<string> result = solve.findRepeatedDnaSequences(str);
	
	//输出写法一
	for (vector<string>::iterator it = result.begin(); it != result.end(); it++) {
		printf("%s\n", (*it).c_str());
	}

	////输出写法二
	//for (int i = 0; i < result.size(); i++) {
	//	printf("%s\n", result[i].c_str());
	//}

	return 0;
}