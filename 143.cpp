#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//解法一
//class Solution {
//public:
//	void reorderList(ListNode* head) {
//		vector<ListNode*> node;
//		ListNode* first = head;
//		while (first)
//		{
//			node.push_back(first);
//			first = first->next;
//		}
//		if (node.size() <= 2)
//			return;
//		for (int i = 0; i < node.size() / 2; i++)
//		{
//			node[i]->next = node[node.size() - 1 - i];
//			node[node.size() - 1 - i]->next = node[i + 1];
//		}
//		node[node.size() / 2]->next = NULL;	
//	}
//};

//解法二
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* newhead = slow->next;
		slow->next = NULL;
		newhead = reverse(newhead);
		while (newhead) {
			ListNode* temp = newhead->next;
			newhead->next = head->next;
			head->next = newhead;
			head = newhead->next;
			newhead = temp;
		}

	}
	ListNode* reverse(ListNode* head) {
		ListNode* new_head = nullptr;
		while (head) {
			ListNode* next = head->next;
			head->next = new_head;
			new_head = head;
			head = next;
		}
		return new_head;
	}
};

int main() {

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	Solution().reorderList(&a);
	ListNode* head = &a;
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << "->NULL";
		}
		head = head->next;
	}

	return 0;
}