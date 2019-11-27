#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head) return head;
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenHead = even;
		while (even && even->next) {
			odd->next = even->next;
			odd = odd->next;
			even->next = odd->next;
			even = even->next;
		}
		odd->next = evenHead;
		return head;
	}
};

int main() {
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	//ListNode d(4);
	//ListNode e(5);
	//ListNode f(6);
	a.next = &b;
	b.next = &c;
	//c.next = &d;
	//d.next = &e;
	//e.next = &f;

	ListNode* head = Solution().oddEvenList(&a);
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