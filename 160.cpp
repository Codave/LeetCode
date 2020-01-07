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
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
		//得到两个链表的长度
		ListNode* p1 = pHead1;
		ListNode* p2 = pHead2;
		int cnt1 = 0, cnt2 = 0;
		while (p1) {
			cnt1++;
			p1 = p1->next;
		}
		while (p2) {
			cnt2++;
			p2 = p2->next;
		}
		p1 = pHead1;
		p2 = pHead2;
		if (cnt1 > cnt2) {
			for (int i = 0; i < cnt1 - cnt2; i++) {
				p1 = p1->next;
			}
		}
		else {
			for (int i = 0; i < cnt2 - cnt1; i++) {
				p2 = p2->next;
			}
		}
		while (p1 && p2) {
			if (p1 == p2) {
				return p1;
			}
			p1 = p1->next;
			p2 = p2->next;
		}
		return NULL;
	}
};


//解法二
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		int list_A_len = get_list_length(headA);
		int list_B_len = get_list_length(headB);
		if (list_A_len > list_B_len) {
			headA = forward_long_list(list_A_len, list_B_len, headA);
		}
		else {
			headB = forward_long_list(list_B_len, list_A_len, headB);
		}
		while (headA && headB) {
			if (headA == headB) {
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return NULL;
	}

	int get_list_length(ListNode* head) {
		int len = 0;
		while (head) {
			len++;
			head = head->next;
		}
		return len;
	}

	ListNode* forward_long_list(int long_len, int short_len, ListNode* head) {
		int delta = long_len - short_len;
		while (head && delta) {
			head = head->next;
			delta--;
		}
		return head;
	}
};


//解法三
class Solution {
public:
	ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
		auto p = headA;
		auto q = headB;
		while (p != q) {
			if (p) {
				p = p->next;
			}
			else {
				p = headB;
			}
			if (q) {
				q = q->next;
			}
			else {
				q = headA;
			}
		}
		return p;
	}
};

int main() {

	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);
	ListNode f(6);
	ListNode g(7);
	ListNode h(8);
	a.next = &b;
	b.next = &f;
	c.next = &d;
	d.next = &e;
	e.next = &f;
	f.next = &g;
	g.next = &h;
	ListNode* head = Solution().getIntersectionNode(&a, &c);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}