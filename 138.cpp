#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};

class Solution {
public:
	Node* copyRandomList(Node* head) {
		map<Node*, int> node_map;   //��ַ���ڵ�λ�õ�map
		vector<Node*> node_vec;    //ʹ��vector��¼������ڵ���ʵ�ַ
		Node* ptr = head;
		int i = 0;
		while (ptr) {
			node_vec.push_back(new Node(ptr->val, NULL, NULL));
			node_map[ptr] = i;    //��¼ԭʼ�����ַ���ڵ�λ�õ�node_map
			ptr = ptr->next;    //����ԭʼ�б�
			i++;    //��¼�ڵ�λ��
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0;
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1];  //����������nextָ��
			if (ptr->random) {
				int id = node_map[ptr->random];
				node_vec[i]->random = node_vec[id];
			}
			ptr = ptr->next;
			i++;
		}
		return node_vec[0];
	}
};

int main() {

	Node a(1, NULL, NULL); 
	Node b(2, NULL, NULL);
	a.next = &b;
	a.random = &b;
	b.random = &b;
	Node* head = Solution().copyRandomList(&a);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}