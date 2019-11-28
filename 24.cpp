#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		
		ListNode dummyHead(0);
		ListNode* p = &dummyHead;
		dummyHead.next = head;
		while (p->next&&p->next->next) {
			ListNode* node1 = p->next;
			ListNode* node2 = node1->next;
			ListNode* next = node2->next;
			node2->next = node1;
			node1->next = next;
			p->next = node2;
			p = node1;
		}
		return dummyHead.next;
	}
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;

	ListNode* head = Solution().swapPairs(&a);
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

	return 0;
}