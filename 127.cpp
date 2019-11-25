#include<vector>
#include<set>
#include<queue>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		map<string, vector<string>> graph;
		construct_graph(beginWord, wordList, graph);
		return BFS_graph(beginWord, endWord, graph);
	}
	int BFS_graph(string& beginWord, string& endWord, map<string, vector<string>>& graph) {
		queue<pair<string, int>> Q;	//��������<���㣬����>
		set<string> visit;	//��¼�ѷ��ʵĶ���
		Q.push(make_pair(beginWord, 1));	//�����ʼ�㣬��ʼ�㲽��Ϊ1
		visit.insert(beginWord);
		while (!Q.empty()) {
			string node = Q.front().first;
			int step = Q.front().second;
			Q.pop();
			if (node == endWord) {
				return step;
			}
			const vector<string>& neighbors = graph[node];	//ȡ�ڽӱ�mapд����key��Ӧ��value
			for (int i = 0; i < neighbors.size(); i++) {
				if (visit.find(neighbors[i]) == visit.end()) {
					Q.push(make_pair(neighbors[i], step + 1));
					visit.insert(neighbors[i]);
				}
			}
		}
		return 0;	//�����з�������
	}
	bool connect(string& word1, string& word2) {
		int cnt = 0;
		for (int i = 0; i < word1.length(); i++) {
			if (word1[i] != word2[i]) {
				cnt++;
			}
		}
		return cnt == 1;
	}
	void construct_graph(string& beginWord, vector<string>& wordList, map<string, vector<string>>& graph) {
		wordList.push_back(beginWord);
		for (int i = 0; i < wordList.size(); i++) {
			graph[wordList[i]] = vector<string>();	//������άvector������
		}
		for (int i = 0; i < wordList.size(); i++) {
			for (int j = i + 1; j < wordList.size(); j++) {
				if (connect(wordList[i], wordList[j])) {
					graph[wordList[i]].push_back(wordList[j]);
					graph[wordList[j]].push_back(wordList[i]);
				}
			}
		}
	}
};

int main() {

	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList;
	wordList.push_back("hot");
	wordList.push_back("dot");
	wordList.push_back("dog");
	wordList.push_back("lot");
	wordList.push_back("log");
	wordList.push_back("cog");
	Solution solve;
	int result = solve.ladderLength(beginWord, endWord, wordList);
	printf("rsult=%d\n", result);

	return 0;
}