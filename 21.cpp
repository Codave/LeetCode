#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode dummyHead(0);
		ListNode* pre = &dummyHead;
		
		while (l1 && l2) {
			if (l1->val < l2->val) {
				pre->next = l1;
				l1 = l1->next;
			}
			else {
				pre->next = l2;
				l2 = l2->next;
			}
			pre = pre->next;
		}
		if (l1) {
			pre->next = l1;
		}
		if (l2) {
			pre->next = l2;
		}
		return dummyHead.next;
	}
};

int main() {
	ListNode a(-9);
	ListNode b(3);
	ListNode c(5);
	ListNode d(7);
	//ListNode e(3);
	//ListNode f(4);
	//ListNode g(5);
	a.next = &b;
	c.next = &d;

	//d.next = &e;
	//e.next = &f;
	//f.next = &g;

	ListNode* head = Solution().mergeTwoLists(&a, &c);
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