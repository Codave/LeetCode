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
		map<Node*, int> node_map;   //地址到节点位置的map
		vector<Node*> node_vec;    //使用vector记录新链表节点访问地址
		Node* ptr = head;
		int i = 0;
		while (ptr) {
			node_vec.push_back(new Node(ptr->val, NULL, NULL));
			node_map[ptr] = i;    //记录原始链表地址至节点位置的node_map
			ptr = ptr->next;    //遍历原始列表
			i++;    //记录节点位置
		}
		node_vec.push_back(0);
		ptr = head;
		i = 0;
		while (ptr) {
			node_vec[i]->next = node_vec[i + 1];  //链接新链表next指针
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