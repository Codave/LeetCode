#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode p(0);
		ListNode q(0);
		ListNode* phead = &p;
		ListNode* qhead = &q;
		ListNode* m = phead;
		ListNode* n = qhead;
		while (head) {
			if (head->val < x) {
				m->next = head;
				m = m->next;
			}
			else {
				n->next = head;
				n = n->next;
			}
			head = head->next;
		}
		m->next = qhead->next;
		n->next = NULL;
		return phead->next;
	}
};

int main() {
	ListNode a(1);
	ListNode b(4);
	ListNode c(3);
	ListNode d(2);
	ListNode e(5);
	ListNode f(2);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	ListNode* head = Solution().partition(&a, 3);
	while (head) {
		if (head->next) {
			cout << head->val << "->";
		}
		else {
			cout << head->val << endl;
		}
		head = head->next;
	}
	return 0;
}