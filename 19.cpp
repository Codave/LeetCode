#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode dummyHead(0);
		dummyHead.next = head;
		ListNode* p = &dummyHead;
		ListNode* q = p;
		for (int i = 0; i < n; i++) {
			q = q->next;
		}
		while (q->next) {
			q = q->next;
			p = p->next;
		}
		p->next = p->next->next;
		return dummyHead.next;
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

	ListNode* head = Solution().removeNthFromEnd(&a, 5);
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