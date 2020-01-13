#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int MAXN = 26;

//�ⷨһ
//class Trie {
//public:
//	Trie() {
//		is_str = NULL;
//		memset(child, 0, sizeof(child));
//		/*for (int i = 0; i < 26; i++) {
//			child[i] = 0;
//		}*/
//	}
//	/** Inserts a word into the trie. */
//	void insert(string word) {
//		Trie* cur = this; // cur��ʼ��Ϊ�����ָ��
//		for (char w : word) { // ����word�е�ÿһ���ַ�
//			if (cur->child[w - 'a'] == NULL) { // ��һ����㲻���ڣ�����һ�����
//				Trie* new_node = new Trie();
//				cur->child[w - 'a'] = new_node;
//			}
//			cur = cur->child[w - 'a'];
//		}
//		cur->is_str = true; // ��ǰ����Ѿ���һ���������ַ�����
//	}
//	/** Returns if the word is in the trie. */
//	bool search(string word) {
//		Trie* cur = this;
//		for (char w : word) {
//			if (cur != NULL)
//				cur = cur->child[w - 'a']; // ����curָ���ָ��ʹ��ָ����һ�����
//		}
//		return (cur != NULL && cur->is_str); // curָ�벻Ϊ����curָ��ָ��Ľ��Ϊһ���������ַ�������ɹ��ҵ��ַ���
//	}
//	/** Returns if there is any word in the trie that starts with the given prefix. */
//	bool startsWith(string prefix) {
//		Trie* cur = this;
//		for (char w : prefix) {
//			if (cur != NULL)
//				cur = cur->child[w - 'a'];
//		}
//		return (cur != NULL); // ���search(),����ֻ���ж�curָ���Ƿ�Ϊ�վ�����
//	}
//private:
//	bool is_str; // ��ʶ��ǰ����Ƿ�Ϊһ���������ַ���
//	Trie* child[MAXN]; // ��һ������ָ������
//};

//�ⷨ��
class Node {
public:
	Node* next[26];
	bool is_end;
	Node() {
		memset(next, NULL, sizeof(next));
		is_end = false;
	}
};
class Trie {
public:
	Node* root;
	Trie() {
		root = new Node();
	}
	void insert(string word) {
		Node* p = root;
		for (int i = 0; i < word.length(); i++) {
			if (p->next[word[i] - 'a'] == NULL) {
				p->next[word[i] - 'a'] = new Node();
			}
			p = p->next[word[i] - 'a'];
		}
		p->is_end = true;
	}
	bool search(string word) {
		Node* p = root;
		for (int i = 0; i < word.length(); i++) {
			if (p->next[word[i] - 'a'] == NULL) {
				return false;
			}
			p = p->next[word[i] - 'a'];
		}
		return p->is_end;
	}
	bool startsWith(string prefix) {
		Node* p = root;
		for (int i = 0; i < prefix.length(); i++) {
			if (p->next[prefix[i] - 'a'] == NULL) {
				return false;
			}
			p = p->next[prefix[i] - 'a'];
		}
		return true;
	}
};

int main() {
	Trie* trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple");   // ���� true
	cout << trie->search("app");     // ���� false
	cout << trie->startsWith("app");
	trie->insert("app");
	cout << trie->search("app");     // ���� true
	return 0;
}
