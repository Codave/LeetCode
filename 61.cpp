#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

//解法一
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (head == NULL|| head->next==NULL || k==0) return head;
		ListNode* p;
		int n = 1;
		for (p = head; p->next; ++n) {	//求链表长度最好用for循环，最后循环结束p不会指向NULL，而是指向最后一个结点
			p = p->next;				//当然p开始是指向head的
		}
		p->next = head;
		
		for (int i = 0; i < n - k % n; i++) {
			p = head;
			head = head->next;
		}
		p->next = NULL;

		return head;
	}
};

//解法二
class Solution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return 0;
		int n = 0;
		for (auto p = head; p; p = p->next) n++;
		k %= n;
		auto first = head, second = head;
		while (k--) first = first->next;
		while (first->next) {
			first = first->next;
			second = second->next;
		}
		first->next = head;
		head = second->next;
		second->next = NULL;
		return head;
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
	ListNode* head = Solution().rotateRight(&a, 2);
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