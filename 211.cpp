//#include<iostream>
//#include<algorithm>
//#include<string>
//using namespace std;
//const int MAXN = 26;
//
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
//			
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
//
//int main() {
//	Trie* trie = new Trie();
//	trie->insert("apple");
//	cout << trie->search("apple");   // ���� true
//	cout << trie->search("app");     // ���� false
//	cout << trie->startsWith("app");
//	trie->insert("app");
//	cout << trie->search("app");     // ���� true
//	return 0;
//}
