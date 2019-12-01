#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode dummyHead(0);
		dummyHead.next = head;
		auto p = head;
		int length = 0;
		while (p) {
			++length;
			p = p->next;
		}

		for (int size = 1; size < length; size <<= 1) {
			auto cur = dummyHead.next;
			auto tail = &dummyHead;

			while (cur) {
				auto left = cur;
				auto right = cut(left, size); 
				cur = cut(right, size); 

				tail->next = merge(left, right);
				while (tail->next) {
					tail = tail->next;
				}
			}
		}
		return dummyHead.next;
	}

	ListNode* cut(ListNode* head, int n) {
		auto p = head;
		while (--n && p) {
			p = p->next;
		}

		if (!p) return nullptr;

		auto next = p->next;
		p->next = nullptr;
		return next;
	}

	ListNode* merge(ListNode* l1, ListNode* l2) {
		ListNode dummyHead(0);
		auto p = &dummyHead;
		while (l1 && l2) {
			if (l1->val < l2->val) {
				p->next = l1;
				p = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				p = l2;
				l2 = l2->next;
			}
		}
		p->next = l1 ? l1 : l2;
		return dummyHead.next;
	}
};

int main() {

	ListNode a(-1);
	ListNode b(5);
	ListNode c(3);
	ListNode d(4);
	ListNode e(0);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	ListNode* head = Solution().sortList(&a);
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