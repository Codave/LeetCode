#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){ }
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) return head;
		ListNode dummy(0);
		dummy.next = head;

		ListNode* cur = head;
		ListNode* pre = NULL;
		while (cur) {
			if (cur->next && cur->next->val < cur->val) {
				pre = &dummy;
				while (cur->next && pre->next && cur->next->val > pre->next->val) {
					pre = pre->next;
				}

				ListNode* temp = cur->next;
				cur->next = temp->next;
				temp->next = pre->next;
				pre->next = temp;
			}
			else {
				cur = cur->next;
			}
		}
		return dummy.next;
	}
};

int main() {
	
	ListNode a(-1);
	ListNode b(5);
	ListNode c(3);
	ListNode d(4);
	ListNode e(0);
	ListNode f(7);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = &f;

	ListNode* head = Solution().insertionSortList(&a);
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