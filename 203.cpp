#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode dummyHead(0);
		ListNode* pre = &dummyHead;
		dummyHead.next = head;

		while (pre->next) {
			if (pre->next->val == val) {
				ListNode* delnext = pre->next;
				pre->next = delnext->next;
			}
			else {
				pre = pre->next;
			}
		}
		return dummyHead.next;
	}
};

int main() {
	ListNode a(1);
	ListNode b(1);
	ListNode c(6);
	ListNode d(3);
	ListNode e(4);
	ListNode f(5);
	ListNode g(6);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;

	ListNode* head = Solution().removeElements(&a, 1);
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